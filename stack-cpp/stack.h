#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
struct node{
	T data;
	node <T> *prev; // this points to what is hypothetically below the element in the stack
};


template <typename T>
class stack{
	public:
		stack();
		~stack();
		void push(T input);
		bool is_empty();
		void traverse();
		void pop();
	private:
		int size; // only used for testing purposes
		node <T> *top; // when returning of type node, indicate via template name
		node <T> *create_node(T input);
};

template <typename T>
stack<T>::stack(){
	this->size = 0;
	this->top = NULL;
}

template <typename T>
stack<T>::~stack(){
	if (is_empty()){
		return;
	}else{
		while(!is_empty()){
			node <T> *temp = this->top;
			this->top = this->top->prev;
			delete temp;
			this->size--;
		}
	}
}

template <typename T>
void stack<T>::push(T c){
	node <T> *new_node = this->create_node(c);
	if (this->is_empty()){
		this->top = new_node;
	}else{
		// this is where stuff is going wrong
		node<T> *temp = this->top;
		this->top = temp;
		new_node->prev = temp;
		this->top = new_node;
	}
	this->size++;
}

template <typename T>
bool stack<T>::is_empty(){
	if (this->top == NULL){
		return true;
	}
	return false;
}

template <typename T>
void stack<T>::pop(){
	if (this->is_empty()){
		return;
	}else{
		node <T> *temp = this->top;
		this->top = this->top->prev;
		delete temp;
		temp = NULL;
		this->size--;
	}
}

template <typename T>
void stack<T>::traverse(){ // get to here and the top->prev has nothing 
	if (this->is_empty()){
		return;
	}else{
		node <T> *temp = this->top;
		while(temp!=NULL){
			std::cout<<temp->data<<std::endl;
			temp = temp->prev;
		}
	}
}

/*
template <typename T>
<T> *stack<T>::peak(){
	if (this->is_empty()){
		return;
	}else{
		return this->top->data;
	}
}
*/

template <typename T>
node <T> * stack<T>::create_node(T c){
	node <T> *new_node = new node<T>;
	new_node->data = c;
	new_node->prev = NULL;
	return new_node;
}

#endif
