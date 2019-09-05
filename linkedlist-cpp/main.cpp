#include <iostream>
#include "linkedlist.h"

int main(){
	std::cout<<"This is a linkedlist"<<std::endl;

	linkedlist *linked_list = new linkedlist;
	linked_list->append(1);
	linked_list->append(2);
	linked_list->append(3);
	linked_list->append(4);
	linked_list->append(5);
	linked_list->traverse(linked_list->return_head());
	std::cout<<linked_list->return_head()<<std::endl;

	delete linked_list;
	return 0;
}
