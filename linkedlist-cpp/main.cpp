#include <iostream>
#include "linkedlist.h"
#include "superlinkedlist.h"

int main(){
	superlinkedlist *mySPL = new superlinkedlist;
	mySPL->append(1);
	mySPL->append(1);
	mySPL->append(1);
	mySPL->append(1);
	mySPL->append(1);
	std::cout<<mySPL->return_size()<<std::endl;
	std::cout<<mySPL->giveSPL()<<std::endl;
}

