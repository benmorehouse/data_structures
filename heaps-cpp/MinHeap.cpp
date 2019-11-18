#include "MinHeap.h"

MinHeap::MinHeap(int _d){
	if(_d <= 0) std::exit(0);
	this->d = _d; 	
	this->addCalls = 0;
}

MinHeap::~MinHeap(){

}

void MinHeap::remove(int item){

}

int MinHeap::add(int item){
	if(this->isEmpty()){
		this->array.push_back(item);
		this->addCalls++;
		return this->addCalls;
	}else{
		this->array.push_back(item);
		this->heapify(this->array.size()-1);	
		this->addCalls++;
		return this->addCalls;
	}
}

void MinHeap::heapify(int index){ // we either call this with index at end or index at root
	if(index == 0){
		// this means we are removing 
		// we heapify going down
		int currentNodeIndex = index; // because we move the last node to the beginning and then we heapify down 
		bool changed = true;
		while(changed){
			int minChildIndex = currentNodeIndex;
			for(int i = (currentNodeIndex * this->d) + 1; i < (currentNodeIndex * this->d) + this->d; i++){
				if(this->array[i] < this->array[minChildIndex]){
				       minChildIndex = i;
				} 
			}

			if (minChildIndex == currentNodeIndex){
				changed = false;
				break;// this means we have no processes to take care of for heapify
			}

			currentNodeIndex = minChildIndex;
		}
	}else{
		if (this->isEmpty()) return;
		int parentIndex = (this->array.size()-2/this->d); // this array minus two instead of one because when we 
								  // call the size function it will return non-zero index
		int currentNodeIndex = (this->array.size()-1);
			
		while(this->array[currentNodeIndex] > this->array[parentIndex]){
			// this means we dont have the min heap property and need to rearrange it...
			std::swap(this->array[currentNodeIndex],this->array[parentIndex]);
			currentNodeIndex = parentIndex;
			parentIndex = (parentIndex-1/this->d);
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
}


