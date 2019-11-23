#include "MinHeap.h"

MinHeap::MinHeap(int _d){
	if(_d <= 0) std::exit(0);
	this->d = _d; 	
	this->addCalls = 0;
}
MinHeap::~MinHeap(){
	for(int i=0;i<this->array.size();i++){
		delete this->array[i];
	}
}

int MinHeap::peek(){
	if(this->isEmpty()) return 0;
	return this->array[0]->val;
}

// what is happening when we remove is that we are saying the correct nth one got eliminated but the value is not corresponding correctly. Specifically it is saying the one in front of it in the order got removed...
void MinHeap::remove(){
	if(this->isEmpty()) return;
	int nthCall = this->array[0]->currentPosition;
	std::swap(this->array[0], this->array[this->array.size()-1]);
	this->array.pop_back();	
	this->nthValueIndexInArray[nthCall] = nullptr; 
	this->bubbleDown(0);
}

int MinHeap::add(int item){
	if(this->isEmpty()){
		Item* newItem = new Item(item, this->addCalls);
		this->array.push_back(newItem);
		this->nthValueIndexInArray.push_back(newItem);	
		this->addCalls++;
		return this->addCalls;
	}else{
		Item* newItem = new Item(item, this->addCalls);
		this->array.push_back(newItem);
		this->nthValueIndexInArray.push_back(newItem);	
		this->bubbleUp(this->array.size()-1);	
		this->addCalls++;
		return this->addCalls;
	}
}

bool MinHeap::isEmpty(){
	return this->array.size() == 0;
}

void MinHeap::print(){
	if(this->isEmpty()) return;
	for(int i = 0;i < this->array.size(); i++){
		std::cout<<this->array[i]->val<<" ";
	}
	std::cout<<std::endl;
	for(int i=0;i<this->array.size();i++){
		if(this->nthValueIndexInArray[i] == nullptr){
			std::cout<<"this element was deleted"<<std::endl;
			continue;
		}
		std::cout<<"the "<<i+1<<"th thing that was added was:"<<this->array[this->nthValueIndexInArray[i]->currentPosition]->val<<std::endl;
	}
}

void MinHeap::update(int nth, int priority){
	if(nth >= this->nthValueIndexInArray.size() || nth < 0){
		//prevents bad input which would lead to seg faults
		return;
	}else if(this->nthValueIndexInArray[nth] == nullptr){
		//this means it was deleted before this operation
		return;
	}else{
		// go through, find the nth value in nthValueIndex, find value in array and then idk what you do after...
		if(this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority < priority){
			//this means it is not going up it is onl going to bubble down
			//bubble down from there
			this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority = priority;
			this->bubbleDown(this->nthValueIndexInArray[nth]->currentPosition);	
		}else{
			this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority = priority;
			this->bubbleUp(this->nthValueIndexInArray[nth]->currentPosition);	
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
			if(this->array[i]->val < this->array[minChildIndex]->val){
				minChildIndex = i;
			} 
		}

		if (minChildIndex == currentNodeIndex){
			changed = false;
			break;// this means we have no processes to take care of for heapify
		}
		std::swap(this->nthValueIndexInArray[this->array[minChildIndex]->currentPosition], this->nthValueIndexInArray[this->array[currentNodeIndex]->currentPosition]);
		std::swap(this->array[minChildIndex],this->array[currentNodeIndex]);
		
		currentNodeIndex = minChildIndex;
	}
}

void MinHeap::bubbleUp(int currentNodeIndex){
	if (this->isEmpty()) return;
	int parentIndex = ((this->array.size()-2)/this->d); // this array minus two instead of one because when we 
	while(this->array[currentNodeIndex]->val < this->array[parentIndex]->val){
		// this means we dont have the min heap property and need to rearrange it...
		std::swap(this->nthValueIndexInArray[this->array[currentNodeIndex]->currentPosition], this->nthValueIndexInArray[this->array[parentIndex]->currentPosition]);
		std::swap(this->array[parentIndex],this->array[currentNodeIndex]);
		currentNodeIndex = parentIndex;
		parentIndex = (parentIndex/this->d);
	}
}

