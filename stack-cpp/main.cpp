#include <iostream>
#include "stack.h"

int main(){
	stack<char> mystack;	
	mystack.push('c');
	mystack.push('c');
	mystack.push('c');
	mystack.push('c');
	mystack.traverse();	
	return 0;
}
