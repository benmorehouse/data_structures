#ifndef SPLAY_H
#define SPLAY_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "../bst/bst.h"
#include <cmath>
#include <math.h> 
/**
* A templated binary search tree implemented as a Splay tree.
*/
template <class Key, class Value>
class SplayTree : public BinarySearchTree<Key, Value>
{
public:
	// Methods for inserting/removing elements from the tree. You must implement
	// both of these methods.
	SplayTree();
	virtual void insert(const std::pair<Key, Value>& keyValuePair) override;
	void remove(const Key& key);
	int report() const;
	Node<Key,Value>* Search(const Key&);
	void resetBadInserts(){this->badInserts = 0;}

private:
	/* You'll need this for problem 5. Stores the total number of inserts where the
	   node was added at level strictly worse than 2*log n (n is the number of nodes
	   including the added node. The root is at level 0). */
	int badInserts;
	void RightRight(Node<Key,Value>*,Node<Key,Value>*,Node<Key,Value>*);
	void LeftLeft(Node<Key,Value>*,Node<Key,Value>*,Node<Key,Value>*);
	void SplayUp(Node<Key,Value>*);
	int splaySize;
	/* Helper functions are encouraged. */
};

/*
--------------------------------------------
Begin implementations for the SplayTree class.
--------------------------------------------
*/

template<typename Key, typename Value>
SplayTree<Key, Value>::SplayTree() : badInserts(0) {
	this->splaySize = 0;
}

template<typename Key, typename Value>
int SplayTree<Key, Value>::report() const {
	return badInserts;
}

/**
* Insert function for a key value pair. Finds location to insert the node and then splays it to the top.
*/
template<typename Key, typename Value>
void SplayTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{
	if(this->mRoot == nullptr){
		Node<Key,Value> *currentNode = new Node<Key,Value>(keyValuePair.first,keyValuePair.second,nullptr);
		this->mRoot = currentNode;
		this->badInserts++;
		this->splaySize++;
		return;
	}
	Node<Key, Value> *currentNode = this->Search(keyValuePair.first);

	if(currentNode->getKey() == keyValuePair.first){
		// this means that the node we tried to insert actually existed beforehand... we should just call a splayup function
		this->SplayUp(currentNode);
	}else{
		this->splaySize++;
		// this means that the node we tried to add doesnt exist so we need to add it
		// currentNode is now the parent of the new node we are going to make.
		if(keyValuePair.first < currentNode->getKey()){
			Node<Key,Value> *newNode = new Node<Key,Value>(keyValuePair.first,keyValuePair.second,currentNode);
			currentNode->setLeft(newNode);
			this->SplayUp(newNode);
		}else{
			Node<Key,Value> *newNode = new Node<Key,Value>(keyValuePair.first,keyValuePair.second,currentNode);
			currentNode->setRight(newNode);
			this->SplayUp(newNode); // endless loop here with insert of 3 which
		}
	}
}

/*
 * This function will traverse down and determine if the node we are trying to add or delete is in the tree
 * if so: it will return the node with value asked for 
 * otherwise it will return the last node that was scanned (which can then be used to add).
 */

template<typename Key, typename Value>
Node<Key,Value>* SplayTree<Key,Value>::Search(const Key& key){
	Node<Key, Value> *currentNode = this->mRoot;
	bool exit = false;
	while(!exit){
		if(key < currentNode->getKey()){
			if(currentNode->getLeft() == nullptr){
				return currentNode;
			}else{
				currentNode = currentNode->getLeft();
				continue;
			}
		}else if(key > currentNode->getKey()){
			if(currentNode->getRight() == nullptr){
				return currentNode;
			}else{
				currentNode = currentNode->getRight();
				continue;
			}
		}else{
			return currentNode;	
		}
	}
	return nullptr;
}

template<typename Key, typename Value>
void SplayTree<Key,Value>::RightRight(Node<Key,Value> *zNode,Node<Key,Value> *yNode,Node<Key,Value> *xNode){
	Node<Key,Value> *T2 = yNode->getLeft();
	if(zNode->getParent() != nullptr){	
		if(zNode == zNode->getParent()->getRight()){
			zNode->getParent()->setRight(yNode);
		}else{
			zNode->getParent()->setLeft(yNode);
		}
	}else{
		this->mRoot = yNode; // this means znode was root before but now y is.
	}

	yNode->setParent(zNode->getParent());
	zNode->setParent(yNode);
	zNode->setRight(T2);
	yNode->setLeft(zNode);
	if(T2 != nullptr){
		T2->setParent(zNode);
	}
}

template<typename Key, typename Value>
void SplayTree<Key,Value>::LeftLeft(Node<Key,Value> *zNode,Node<Key,Value> *yNode,Node<Key,Value> *xNode){
	Node<Key,Value> *T3 = yNode->getRight();
	if(zNode->getParent() != nullptr){	
		yNode->setParent(zNode->getParent());
		if(zNode == zNode->getParent()->getRight()){
			zNode->getParent()->setRight(yNode);
		}else{
			zNode->getParent()->setLeft(yNode);
		}
	}else{
		this->mRoot = yNode;
	}
	yNode->setParent(zNode->getParent());
	zNode->setParent(yNode);
	zNode->setLeft(T3);
	yNode->setRight(zNode);
	if(T3 != nullptr){
		T3->setParent(zNode);
	}
}

template<typename Key, typename Value>
void SplayTree<Key, Value>::SplayUp(Node<Key,Value>* currentNode){
	bool atRoot = false;
	int steps = 0;
	while(!atRoot){
		if(currentNode == this->mRoot){
			return; // better to have an early return here.
		}
		if(currentNode->getParent() == this->mRoot){ 
			if(this->mRoot->getLeft() == currentNode){
				// we then do a right rotation and thats it because we are at the root.
				Node<Key,Value>* zNode = currentNode->getParent();
				Node<Key,Value>* yNode = currentNode;
				Node<Key,Value>* xNode = yNode->getLeft();
				this->LeftLeft(zNode,yNode,xNode);
				return;
			}else{
				Node<Key,Value>* zNode = currentNode->getParent();
				Node<Key,Value>* yNode = currentNode;
				Node<Key,Value>* xNode = yNode->getRight();
				this->RightRight(zNode,yNode,xNode);
				return;
			}
		}else{ // the tree is a height of at least 3
			Node<Key,Value>*parent = currentNode->getParent();
		       	if(parent->getRight() == currentNode && parent->getParent()->getLeft() == parent){ 
				Node<Key,Value>* zNode = parent;
				Node<Key,Value>* yNode = currentNode;
				Node<Key,Value>* xNode = currentNode->getRight();
				this->RightRight(zNode,yNode,xNode);
				steps++;
				this->LeftLeft(yNode->getParent(),yNode,zNode);
				steps++;
			}else if(parent->getLeft() == currentNode && parent->getParent()->getRight() == parent){
				//right left
				Node<Key,Value>* zNode = parent;
				Node<Key,Value>* yNode = currentNode;
				Node<Key,Value>* xNode = currentNode->getLeft();
				this->LeftLeft(zNode,yNode,xNode);			
				steps++;
				this->RightRight(yNode->getParent(),yNode,zNode);
				steps++;
			}else if(parent->getLeft() == currentNode && parent->getParent()->getLeft() == parent){
				Node<Key,Value>* zNode = parent->getParent(); 
				Node<Key,Value>* yNode = parent;
				Node<Key,Value>* xNode = currentNode;
				this->LeftLeft(zNode,yNode,xNode);
				steps++;
				this->LeftLeft(yNode,xNode,xNode->getLeft());
				steps++;
			}else{
				Node<Key,Value>* zNode = parent->getParent();
				Node<Key,Value>* yNode = parent;
				Node<Key,Value>* xNode = currentNode;
				this->RightRight(zNode,yNode,xNode);
				steps++;
				this->RightRight(yNode,xNode,xNode->getRight());
				steps++;
			}
		}
	}

	if(steps > (2 * (log2(this->splaySize)))){
		this->badInserts++;
	}
}

/*
* Remove function for a given key. Finds the node, reattaches pointers, and then splays the parent
* of the deleted node to the top.
*/

template<typename Key, typename Value>
void SplayTree<Key, Value>::remove(const Key& key)
{
	if(this->mRoot == nullptr){
		return;
	}
	
	Node<Key, Value> *currentNode = this->Search(key); // search goes and finds key, and if key doesnt exist in tree it returns last accessed node

	this->SplayUp(currentNode);
	//first we use splay function and push to the top.
	//Next we check to see if it was the key we wanted to delete. If not, our work is done.
	if(currentNode->getKey() == key){
		this->splaySize--;
		Node<Key, Value> *leftRoot = currentNode->getLeft();// then we split up into two subtrees to find new root
		Node<Key, Value> *rightRoot = currentNode->getRight();
		if(leftRoot == nullptr && rightRoot == nullptr){
			delete currentNode;
			this->mRoot = nullptr;
			return;
		}else if(leftRoot == nullptr){
			this->mRoot = rightRoot;
			delete currentNode;
			return;
		}else{
			while(leftRoot->getRight() != nullptr){ // find max of left subtree
				leftRoot = leftRoot->getRight();
			}
			// now leftRoot is now the max value of left subtree. make it new root and delete currentNode
			if(leftRoot->getParent() != currentNode){
				leftRoot->getParent()->setRight(leftRoot->getLeft());
				this->mRoot = leftRoot;
				leftRoot->setParent(nullptr);
				leftRoot->setLeft(currentNode->getLeft());
				leftRoot->setRight(currentNode->getRight());
				delete currentNode;
			}else{
				this->mRoot = leftRoot;	
				leftRoot->setLeft(leftRoot->getLeft());
				leftRoot->setRight(currentNode->getRight());
				leftRoot->setParent(nullptr);
				delete currentNode;
			}
		}
	}
}

/*
------------------------------------------
End implementations for the SplayTree class.
------------------------------------------
*/

#endif
