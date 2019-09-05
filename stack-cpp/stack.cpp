#include "stack.h"
#include <iostream>

stack::stack(){
	this->size = 0;
	this->top = NULL;
}

stack::~stack(){
	if (is_empty()){
		return;
	}else{
		while(!is_empty()){
			node *temp = this->top;
			this->top = this->top->prev;
			delete temp;
			this->size--;
		}
	}
}

void stack::push(char c){
	node *new_node = this->create_letter(c);
	if (this->is_empty()){
		std::cout<<"was an empty stack"<<std::endl;	
		this->top = new_node;
	}else{
		this->top->prev = new_node;
		this->top = new_node;
	}
	this->size++;
}

bool stack::is_empty(){
	if (this->top == NULL){
		return true;
	}
	return false;
}

void stack::pop(){
	if (this->is_empty()){
		return;
	}else{
		node *temp = this->top;
		this->top = this->top->prev;
		delete temp;
		temp = NULL;
		this->size--;
	}
}

void stack::traverse(){ // get to here and the top->prev has nothing 
	if (this->is_empty()){
		return;
	}else{
		node *temp = this->top;
		while(temp!=NULL){
			std::cout<<temp->data<<std::endl;
			temp = temp->prev;
		}
	}
}

node* stack::create_letter(char c){
	node *new_letter = new node;
	new_letter->data = c;
	new_letter->prev = NULL;
	return new_letter;
}

