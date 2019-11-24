#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include "MinHeap.h"

int main(){
	MinHeap<std::string> heap(3);
	heap.add("one",1);
	heap.add("two",3);
	heap.update(1,4);
	std::cout<<"\n\n\n\n\n"; // look at this last call to remove
	std::cout<<"print returns:"<<std::endl; heap.print();
	heap.update(1,0);
	std::cout<<"print returns:"<<std::endl; heap.print();
	return 0;
}
