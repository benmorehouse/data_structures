#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
	struct Item {
		int priority;	// its priority
		T val; // its value. 
		int currentPosition;// stands for the nodes current position in the array.
		int nthTimeAdded;// stands for when the node was added ie its position index in this->nthValueIndexInArray
	
		Item(T v, int p, int nth, int _nthTimeAdded){
			val = v;
			priority = p; // for now it will be v because of testing but later on we will update the priority to be whatever we have in our A* search...
			currentPosition = nth;
			nthTimeAdded = _nthTimeAdded;
		}
	};

	public:
		MinHeap (int);
	/* Constructor that builds a d-ary Min Heap
	  This should work for any d >= 2,
	  but doesn't have to do anything for smaller d.*/

		~MinHeap ();

		int add (T item, int priority);
		 /* adds the item to the heap, with the given priority. 
		    multiple identical items can be in the heap simultaneously. 
		    Returns the number of times add has been called prior to this
		    call (for use with the update function).*/

		const T & peek (); // this will return the templated value T
		 /* returns the element with smallest priority.  
		    If two elements have the same priority, use operator< on the 
		    T data, and return the one with smaller data.*/

		void remove ();
		 /* removes the element with smallest priority, with the same tie-breaker
		    as peek. */

		void update (int nth, int priority);
		 /* finds the nth item (where nth is 0-based) that has ever been added 
		    to the heap (the node that was created on the nth call to add), 
		    and updates its priority accordingly. */

		bool isEmpty ();
		 /* returns true iff there are no elements on the heap. */
		void print(); // used for testing purposes... get rid of this!

	private:
		std::vector<Item*> array; 
		int d; // d is the max size of each branch 
		//std::vector<int> nthValue; // this indexing is aligned with the indexing for array. the value will be the nth time it was added. If it was deleted then it will be evaluated to -1
		std::vector<Item*> nthValueIndexInArray; // just keeps a pointer to the item and then when we want it we can just access it
		
		int addCalls; // dont get rid of this... size of vectors is variable! So keep this as a constant separate from them
		void bubbleDown(int);		
		void bubbleUp(int);		
		// whatever you need to naturally store things.
// You may also add helper functions here.
};

template <typename T>
MinHeap<T>::MinHeap(int _d){
	if(_d <= 0) std::exit(0);
	this->d = _d; 	
	this->addCalls = 0;
}

template <typename T>
MinHeap<T>::~MinHeap(){
	for(int i=0;i<this->array.size();i++){
		delete this->array[i];
	}
}

template <typename T>
const T& MinHeap<T>::peek(){
	if(this->isEmpty()) return 0;
	return this->array[0]->val;
}

// what is happening when we remove is that we are saying the correct nth one got eliminated but the value is not corresponding correctly. Specifically it is saying the one in front of it in the order got removed...

template <typename T>
void MinHeap<T>::remove(){
	if(this->isEmpty()) return;
	int nthCall = this->array[0]->nthTimeAdded; // we want to find out when it was called...
	this->nthValueIndexInArray[nthCall] = nullptr; 
	std::swap(this->array[0], this->array[this->array.size()-1]);
	delete this->array[this->array.size()-1];
	this->array.pop_back();	
	this->array[0]->currentPosition = 0;	
	this->bubbleDown(0);
}

template <typename T>
int MinHeap<T>::add(T item, int priority){
	if(this->isEmpty()){
		Item* newItem = new Item(item,priority,0,this->addCalls);
		this->array.push_back(newItem);
		this->nthValueIndexInArray.push_back(newItem);	
		this->addCalls++;
		return this->addCalls;
	}else{
		Item* newItem = new Item(item,priority, this->array.size(),this->addCalls);
		this->array.push_back(newItem);
		this->nthValueIndexInArray.push_back(newItem);	
		this->bubbleUp(this->array.size()-1);	
		this->addCalls++;
		return this->addCalls;
	}
}

template <typename T>
bool MinHeap<T>::isEmpty(){
	return this->array.size() == 0;
}

template <typename T>
void MinHeap<T>::print(){
	for(int i = 0;i < this->array.size(); i++){
		std::cout<<this->array[i]->val<<" ";
	}
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<std::endl;
	for(int i=0;i<this->nthValueIndexInArray.size();i++){
		if(this->nthValueIndexInArray[i] == nullptr){
			std::cout<<"this element was deleted"<<std::endl;
			continue;
		}
//		std::cout<<"the "<<i+1<<"th thing that was added has position:"<<this->nthValueIndexInArray[i]->currentPosition<<std::endl;
		std::cout<<"the "<<i+1<<"th thing that was added was:"<<this->array[this->nthValueIndexInArray[i]->currentPosition]->val<<std::endl;
	}
}

template <typename T>
void MinHeap<T>::update(int nth, int priority){
	nth--;
	std::cout<<"nth is:"<<nth<<std::endl;
	std::cout<<"priority is:"<<priority<<std::endl;
	if(nth >= this->nthValueIndexInArray.size() || nth < 0){ // the obvious constrants for nth value
		return;
	}else if(this->nthValueIndexInArray[nth] == nullptr){ // this means that this query has been deleted
		return;
	}else{
		// go through, find the nth value in nthValueIndex, find value in array and then idk what you do after...
		std::cout<<"test"<<std::endl;
		std::cout<<this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority<<std::endl;
		if(this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority < priority){ // if what we are changing to is greater than current value...
			this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority = priority;
			this->bubbleDown(this->nthValueIndexInArray[nth]->currentPosition);	
		}else{
			this->array[this->nthValueIndexInArray[nth]->currentPosition]->priority = priority;
			this->bubbleUp(this->nthValueIndexInArray[nth]->currentPosition);	
		}
	}
}

template <typename T>
void MinHeap<T>::bubbleDown(int currentNodeIndex){
	bool changed = true;	
	while(changed){
		int minChildIndex = currentNodeIndex;
		for(int i = (currentNodeIndex * this->d) + 1; i < (currentNodeIndex * this->d) + this->d+1; i++){
			if (i >= this->array.size() || minChildIndex >= this->array.size()){
				break;
			}
			if(this->array[i]->priority < this->array[minChildIndex]->priority){
				minChildIndex = i;
			} 
		}

		if (minChildIndex == currentNodeIndex){
			changed = false;
			break;// this means we have no processes to take care of for heapify
		}
//		std::swap(this->nthValueIndexInArray[this->array[minChildIndex]->currentPosition], this->nthValueIndexInArray[this->array[currentNodeIndex]->currentPosition]);
		std::swap(this->array[minChildIndex],this->array[currentNodeIndex]);
		this->array[minChildIndex]->currentPosition = minChildIndex;
		this->array[currentNodeIndex]->currentPosition = currentNodeIndex;
		currentNodeIndex = minChildIndex;
	}
}

template <typename T>
void MinHeap<T>::bubbleUp(int currentNodeIndex){
	if (this->isEmpty()) return;
	int parentIndex = ((this->array.size()-2)/this->d); // this array minus two instead of one because when we 
	while(this->array[currentNodeIndex]->priority < this->array[parentIndex]->priority){
		// this means we dont have the min heap property and need to rearrange it...
//		std::swap(this->nthValueIndexInArray[this->array[currentNodeIndex]->currentPosition], this->nthValueIndexInArray[this->array[parentIndex]->currentPosition]);
		std::swap(this->array[parentIndex],this->array[currentNodeIndex]);
		this->array[parentIndex]->currentPosition = parentIndex;
		this->array[currentNodeIndex]->currentPosition = currentNodeIndex;
		currentNodeIndex = parentIndex;
		parentIndex = (parentIndex/this->d);
	}
}

