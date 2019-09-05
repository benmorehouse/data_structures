#include <iostream> 
#include "linkedlist.h"

linkedlist::linkedlist(){
	this->head = NULL;
	this->size = 0;
	this->tail = NULL;
}

linkedlist::~linkedlist(){
	node* cur_node = this->head;	
	while (cur_node != NULL){
		node* temp = cur_node->next;
		delete cur_node;
		cur_node = temp;
	}
	std::cerr<<cur_node<<std::endl;
}

int linkedlist::return_size(){
	if (this->head == NULL){
		return 0;
	}else{
		return this->size;
	}
}

void linkedlist::append(int input){
	node* new_node = new node();
	if(this->tail == NULL){
		new_node->prev = NULL;	
		new_node->next = NULL;
		new_node->data = input;	
		this->head = new_node;
		this->tail = new_node;
	}else{
		this->tail->next = new_node;
		new_node->prev = this->tail;	
		new_node->data = input;
		new_node->next = NULL;
		this->tail = new_node;
	}
	this->size++;
}

void linkedlist::traverse(node *entered_node){
	if (entered_node == NULL){
		std::cout<<"entered_node is empty"<<std::endl;
		return;
	}else{
		std::cout<<"element is: "<<entered_node->data<<std::endl;
		this->traverse(entered_node->next);
	}
}

node* linkedlist::return_head(){ // this returns a node not the data
	if (this->head == NULL){
		return NULL;
	}else{
		return this->head;
	}
}

