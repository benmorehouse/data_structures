#ifndef BST_H
#define BST_H

#include <vector>

class Node {
public:
	Node(Node *left, Node *right, int key) {
		this->left = left;
		this->right = right;
		this->key = key;
	};

	Node(int key) {
		this->left = nullptr;
		this->right = nullptr;
		this->key = key;
	}

	Node *left;
	Node *right;
	int key;

	bool isBST(Node *root);
	bool isBalanced(Node *root);
	bool isBSTHelper(Node *root,int,int);
	int getHeight(Node *root);
};

#endif
