#include "MinHeap.h"

MinHeap::MinHeap(int _d){
	if(_d <= 0) std::exit(0);
	this->d = _d; 	
	this->addCalls = 0;
}

MinHeap::~MinHeap(){

}

int MinHeap::peek(){
	if(this->isEmpty()) return 0;
	return this->array[0];
}
// what is happening when we remove is that we are saying the correct nth one got eliminated but the value is not corresponding correctly. Specifically it is saying the one in front of it in the order got removed...
void MinHeap::remove(){
	if(this->isEmpty()) return;
	std::swap(this->nthValue[0], this->nthValue[this->nthValue.size()-1]);
	this->nthValueIndexInArray[this->nthValue[this->nthValue.size()-1]] = -1; // this goes to the 
	this->nthValue.pop_back();
	std::swap(this->array[0], this->array[this->array.size()-1]);
	this->array.pop_back();	
	this->heapify(0);
}

int MinHeap::add(int item){
	if(this->isEmpty()){
		this->array.push_back(item);
		this->nthValue.push_back(this->addCalls);
		this->nthValueIndexInArray.push_back(0);	
		this->addCalls++;
		return this->addCalls;
	}else{
		this->array.push_back(item);
		this->nthValue.push_back(this->addCalls);
		this->nthValueIndexInArray.push_back(this->array.size()-1);	
		this->heapify(this->array.size()-1);	
		this->addCalls++;
		return this->addCalls;
	}
}

void MinHeap::heapify(int index){ // we either call this with index at end or index at root
	if(index == 0){
		this->bubbleDown(0);	
	}else{
		this->bubbleUp(this->array.size()-1);
	}
}

bool MinHeap::isEmpty(){
	return this->array.size() == 0;
}

void MinHeap::print(){
	if(this->isEmpty()) return;

	for(int i = 0;i < this->array.size(); i++){
		std::cout<<this->array[i]<<" ";
	}
	std::cout<<std::endl;
	for(int i = 0;i < this->nthValueIndexInArray.size(); i++){
		std::cout<<"nthValueIndexInArray:"<<this->nthValueIndexInArray[i]<<std::endl;
	}
	for(int i = 0;i < this->nthValueIndexInArray.size(); i++){
		if(this->nthValueIndexInArray[i] == -1){
			std::cout<<"this element got removed from array"<<std::endl;
			continue;
		}
		std::cout<<"the "<<i+1<<"th term added to array is"<<this->array[this->nthValueIndexInArray[i]]<<" "<<std::endl;
	}
/*
	std::cout<<"HELLO "<<this->array[this->nthValueIndexInArray[3]]<<std::endl; // this tells us where to look in array... specifically here you are going to look at what was added the 4th time
	std::cout<<this->nthValue[this->nthValueIndexInArray[3]]<<std::endl; //this->nthValueIndexInArray[3] 
	std::cout<<"the first term added to the array was:"<<this->array[this->nthValueIndexInArray[0]]<<" and it now is in the index:"<<this->nthValue[0]<<std::endl;
	std::cout<<this->nthValueIndexInArray[3]<<std::endl;

	std::cout<<std::endl;
	
	for(int i = 0;i < this->nthValue.size(); i++){
		std::cout<<this->nthValue[i]<<" ";
	}
*/
}

void MinHeap::update(int nth, int priority){
	if(nth >= this->nthValueIndexInArray.size() || nth < 0){
		//prevents bad input which would lead to seg faults
		return;
	}else if(this->nthValueIndexInArray[nth] == -1){
		//this means it was deleted before this operation
		return;
	}else{
		// go through, find the nth value in nthValueIndex, find value in array and then idk what you do after...
		this->array[this->nthValueIndexInArray[nth]] = priority;
		int currentIndex = this->nthValueIndexInArray[nth]; 
		int parentIndex = ((currentIndex-1)/this->d); // this array minus two instead of one because when we 
		bool changed = true;
		while(changed){
			if(this->array[currentIndex] < this->array[parentIndex]){
				//this means it is not going up it is onl going to bubble down
				//bubble down from there
				this->bubbleDown(currentIndex);	
			}else{
				this->bubbleUp(currentIndex);	
			}

		}
		// it is now changed, so we need to bubble up or bubble down.
	}
}

void MinHeap::bubbleDown(int currentNodeIndex){
	bool changed = true;	
	while(changed){
		int minChildIndex = currentNodeIndex;
		for(int i = (currentNodeIndex * this->d) + 1; i < (currentNodeIndex * this->d) + this->d+1; i++){
			if (i >= this->array.size() || minChildIndex >= this->array.size()){
				break;
			}
			if(this->array[i] < this->array[minChildIndex]){
				minChildIndex = i;
			} 
		}

		if (minChildIndex == currentNodeIndex){
			changed = false;
			break;// this means we have no processes to take care of for heapify
		}

		std::swap(this->array[minChildIndex],this->array[currentNodeIndex]);	
		std::swap(this->nthValueIndexInArray[this->nthValue[minChildIndex]],this->nthValueIndexInArray[this->nthValue[currentNodeIndex]]);
		std::swap(this->nthValue[minChildIndex],this->nthValue[currentNodeIndex]);	
		currentNodeIndex = minChildIndex;
	}
}


void MinHeap::bubbleUp(int currentNodeIndex){
	if (this->isEmpty()) return;
	int parentIndex = ((this->array.size()-2)/this->d); // this array minus two instead of one because when we 
	while(this->array[currentNodeIndex] < this->array[parentIndex]){
		// this means we dont have the min heap property and need to rearrange it...
		std::swap(this->array[currentNodeIndex],this->array[parentIndex]);
		std::swap(this->nthValueIndexInArray[this->nthValue[parentIndex]],this->nthValueIndexInArray[this->nthValue[currentNodeIndex]]);
		std::swap(this->nthValue[parentIndex],this->nthValue[currentNodeIndex]);	
		currentNodeIndex = parentIndex;
		parentIndex = (parentIndex/this->d);
	}
}

