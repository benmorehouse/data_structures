#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "MinHeap.h"

int main(){
	MinHeap heap(2);
	heap.add(1);
	std::cout<<"\n\n\n\n\n"; // look at this last call to remove
	std::cout<<"print returns:"<<std::endl; heap.print();
	return 0;
}
