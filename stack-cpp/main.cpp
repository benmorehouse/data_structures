#include <iostream>
#include "stack.h"

int main(){
	stack *mystack = new stack;
	mystack->push('x');
	mystack->push('y');
	mystack->traverse();
	delete mystack;

}



