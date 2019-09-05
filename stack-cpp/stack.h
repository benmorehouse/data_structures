#ifndef STACK_H
#define STACK_H

struct node{
	char data;
	node *prev;
};

class stack{
	public:
		stack();
		~stack();
		void push(char c);
		bool is_empty();
		void traverse();
		void pop();
	private:
		int size; // only used for testing purposes
		
		node *top;
		node *create_letter(char c);
};

#endif
