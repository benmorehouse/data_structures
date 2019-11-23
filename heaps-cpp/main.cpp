#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "MinHeap.h"

int main(){
	MinHeap heap(2);
	heap.add(4);
	heap.add(7);
	heap.add(9);
	heap.add(11);
	heap.add(5);
	heap.add(1);
	heap.add(2);
	heap.add(7);
	heap.add(7);
	heap.add(1);
	heap.add(0);
	heap.add(7);
	heap.add(7);
	heap.remove(); // just the first remove is out of whack then the rest of them are fine
	heap.remove();
	heap.remove();
	heap.remove();
	heap.remove();
	heap.remove();
	heap.remove(); 
	std::cout<<"print returns:"<<std::endl; heap.print();
	return 0;
}
