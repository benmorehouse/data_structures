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

void MinHeap::remove(){
	if(this->isEmpty()) return;
	std::swap(this->array[0], this->array[this->array.size()-1]);
	this->array.pop_back();	
	this->heapify(0);
}

int MinHeap::add(int item){
	if(this->isEmpty()){
		this->array.push_back(item);
		this->addCalls++;
		this->addHistory.push_back(item);	
		return this->addCalls;
	}else{
		this->array.push_back(item);
		this->heapify(this->array.size()-1);	
		this->addCalls++;
		this->addHistory.push_back(item);	
		return this->addCalls;
	}
}

void MinHeap::heapify(int index){ // we either call this with index at end or index at root
	if(index == 0){
		// this means we are removing 
		// we heapify going down
		int currentNodeIndex = 0; // because we move the last node to the beginning and then we heapify down 
		// call the size function it will return non-zero index
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
			currentNodeIndex = minChildIndex;
		}
	}else{
		if (this->isEmpty()) return;
		int parentIndex = ((this->array.size()-2)/this->d); // this array minus two instead of one because when we 
		int currentNodeIndex = (this->array.size()-1);
		while(this->array[currentNodeIndex] < this->array[parentIndex]){
			// this means we dont have the min heap property and need to rearrange it...
			std::swap(this->array[currentNodeIndex],this->array[parentIndex]);
			currentNodeIndex = parentIndex;
			parentIndex = (parentIndex/this->d);
		}
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
	for(int i = 0;i < this->addHistory.size();i++){
		std::cout<<this->addHistory[i]<<" ";
	}
}

void MinHeap::update(int nth, int priority){
	if(nth > this->addHistory.size()){
		return;
	}
	int desiredNumber = this->addHistory[nth];
	int left = 0;
	int right = this->addHistory.size()-1;
	int index = -1;
	while(left != right){
		if(this->array[left] == desiredNumber){
			index = left;
			break;	
		}
		else if(this->array[right] == desiredNumber){
			index = right;
			break;	
		}
	}

	if(index == -1){
		return;
	}else{
		this->array[index] = priority;
		this->heapify(index);
	}
}


