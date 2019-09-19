#include <iostream> 
#include "linkedlist.h"
#include "superlinkedlist.h"

superlinkedlist::superlinkedlist(){

}

superlinkedlist::~superlinkedlist(){
}

int superlinkedlist::giveSPL(){
	int size = this->return_size();
	int count =1;
	for(int i=1;i<=size;i++){
		count*=i;
	}
	return count;
}



