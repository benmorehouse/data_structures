#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "MinHeap.h"

int main(){
	MinHeap heap(2);
	heap.add(0);
	heap.add(1);
	heap.add(2);
	heap.add(3);
	heap.add(4);
	heap.add(5);
	heap.remove();
	std::cout<<"print returns:"<<std::endl; heap.print();
	return 0;
}
