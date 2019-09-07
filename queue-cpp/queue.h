#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename T>
struct node{
	T data;
	node <T> *prev; // this points to what is hypothetically below the element in the queue 
};


template <typename T>
class queue{
	public:
		queue();
		~queue();
		void push(T input);
		bool is_empty();
		void traverse();
		void pop();
		int return_size();
		T peak();
		T tail();
	private:
		int size; // only used for testing purposes
		node <T> *top; // when returning of type node, indicate via template name
		node <T> *create_node(T input);
		node <T> *return_tail_node(); // used to return tail and also for deletion
};

template <typename T>
queue<T>::queue(){
	this->size = 0;
	this->top = NULL;
}

template <typename T>
queue<T>::~queue(){
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
void queue<T>::push(T c){
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
bool queue<T>::is_empty(){
	if (this->top == NULL){
		return true;
	}
	return false;
}

template <typename T>
void queue<T>::pop(){
	if (this->is_empty()){
		return;
	}else{
		node <T> *new_tail_temp = this->top;	
		node <T> *temp = this->top->prev; 
		delete temp;
		temp = NULL;
		this->size--;
	}
}

template <typename T>
void queue<T>::traverse(){ // get to here and the top->prev has nothing 
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

template <typename T>
node <T> *queue<T>::return_tail_node(){
	if (this->is_empty()){
		return NULL;
	}else{
		node <T> *temp = this->top;
		while (temp->prev != NULL){
			temp = temp->prev;
		}
		return temp;
	}
}

template <typename T>
T queue<T>::peak(){
	if (this->is_empty()){
		return 0;
	}else{
		return this->top->data;
	}
}

template <typename T>
T queue<T>::tail(){
	if (this->is_empty()){
		return;
	}else{
		return this->return_tail_node()->data;
	}
}

template <typename T>
node <T> * queue<T>::create_node(T c){
	node <T> *new_node = new node<T>;
	new_node->data = c;
	new_node->prev = NULL;
	return new_node;
}

template <typename T>
int queue<T>::return_size(){
	if (this->is_empty()){
		return 0;
	}else{
		return this->size;
	}
}

#endif
