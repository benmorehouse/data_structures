#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node{
	int data;
	node* next;
	node* prev;
};

class linkedlist{
	public:
		linkedlist();
		~linkedlist();
		
		int return_size();
		void append(int);
		void traverse(node*);
		node *return_head();

	private:
		node *head;
		node *tail;
		int size;
};

#endif
