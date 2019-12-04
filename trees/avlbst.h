#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "bst.h"

/**
* A special kind of node for an AVL tree, which adds the height as a data member, plus 
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
	// Constructor/destructor.
	AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
	virtual ~AVLNode();

	// Getter/setter for the node's height.
	int getHeight() const;
	void setHeight(int height);

	// Getters for parent, left, and right. These need to be redefined since they 
	// return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
	// for more information.
	virtual AVLNode<Key, Value>* getParent() const override;
	virtual AVLNode<Key, Value>* getLeft() const override;
	virtual AVLNode<Key, Value>* getRight() const override;

protected:
	int mHeight;
};

/*
--------------------------------------------
Begin implementations for the AVLNode class.
--------------------------------------------
*/

/**
* Constructor for an AVLNode. Nodes are initialized with a height of 0.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent)
	: Node<Key, Value>(key, value, parent)
	, mHeight(0)
{

}

/**
* Destructor.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* Getter function for the height. 
*/
template<typename Key, typename Value>
int AVLNode<Key, Value>::getHeight() const
{
	return mHeight;
}

/**
* Setter function for the height. 
*/
template<typename Key, typename Value>
void AVLNode<Key, Value>::setHeight(int height)
{
	mHeight = height;
}

/**
* Getter function for the parent. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getParent() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mParent);
}

/**
* Getter function for the left child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mLeft);
}

/**
* Getter function for the right child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mRight);
}

/*
------------------------------------------
End implementations for the AVLNode class.
------------------------------------------
*/

/**
* A templated balanced binary search tree implemented as an AVL tree.
*/
template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
	// Methods for inserting/removing elements from the tree. You must implement
	// both of these methods. 
	virtual void insert(const std::pair<Key, Value>& keyValuePair) override;
	void remove(const Key& key);

private:
	/* Helper functions are strongly encouraged to help separate the problem
	   into smaller pieces. You should not need additional data members. */
	void LeftLeft(AVLNode<Key,Value>*,AVLNode<Key,Value>*,AVLNode<Key,Value>*);
	void RightLeft(AVLNode<Key,Value>*,AVLNode<Key,Value>*,AVLNode<Key,Value>*);
	void LeftRight(AVLNode<Key,Value>*,AVLNode<Key,Value>*,AVLNode<Key,Value>*);
	void RightRight(AVLNode<Key,Value>*,AVLNode<Key,Value>*,AVLNode<Key,Value>*);
};

/*
--------------------------------------------
Begin implementations for the AVLTree class.
--------------------------------------------
*/

/**
* Insert function for a key value pair. Finds location to insert the node and then balances the tree. 
*/
template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{
	/*
	 *	 psuedocode
	 *
	 *	 1. insert into binary search tree.
	 *	 2. recurse up and update heights as we go
	 *	 	check to make sure node heights never differ by more than one.
	 *	 	If they do have an inbalance, then you need to rotate accordingly.
	 *	 	After you rotate, update and ensure that they are balanced.
	 *	 
	 */	
	AVLNode<Key,Value> *currentNode = this->BSTinsertion(keyValuePair); // first we do some basic insertion!
	if(currentNode == nullptr){
		return;
	}
	currentNode->mHeight = 1;

	bool balanced = true;
	while(balanced){
		if(std::abs(currentNode->getLeft()->mHeight - currentNode->getRight()->mHeight) > 1){
			// then it is unbalanced at this node and this is where we need to start rotating!
			AVLNode<Key,Value> *zNode = currentNode; // first we do some basic insertion!
			AVLNode<Key,Value> *yNode = currentNode; // first we do some basic insertion!
			AVLNode<Key,Value> *xNode = currentNode; // first we do some basic insertion!
			if(keyValuePair->first < currentNode->getKey()){
				*yNode = currentNode->getLeft(); // first we do some basic insertion!
			}else{
				*yNode = currentNode->getRight(); // first we do some basic insertion!
			}

			if(keyValuePair->first < yNode->getKey()){
				*xNode = yNode->getLeft(); // first we do some basic insertion!
			}else{
				*xNode = yNode->getRight(); // first we do some basic insertion!
			}
			// we now have the z,y, & x nodes... lets go ahead and do our rotations!
		}else{
			currentNode->mHeight = std::max(currentNode->getLeft()->mHeight,currentNode->getRight()->mHeight);
			if(currentNode == this->mRoot){
				break;
			}else{
				currentNode = currentNode->getParent();
				continue;
			}
		}



				
	}
}
/* 
 * Each one of these four is to help with the rotations that are neccessary for add and remove...
 */
template<typename Key, typename Value>
void AVLTree<Key,Value>::LeftLeft(AVLNode<Key,Value> *zNode,AVLNode<Key,Value> *yNode,AVLNode<Key,Value> *xNode){
	AVLNode<Key,Value> *T3 = yNode->getRight();
	if(zNode == zNode->getParent->getRight()){
		zNode->getParent()->setRight(yNode);
	}else{
		zNode->getParent()->setLeft(yNode);
	}
	zNode->setParent(yNode);
	zNode->setLeft(T3);
	yNode->setRight(zNode);
	T3->setParent(zNode);
}

template<typename Key, typename Value>
void AVLTree<Key,Value>::RightLeft(AVLNode<Key,Value> *zNode,AVLNode<Key,Value> *yNode,AVLNode<Key,Value> *xNode){
	AVLNode<Key,Value> *T3 = xNode->getRight();
	zNode->setRight(xNode);
	xNode->setParent(zNode);
	yNode->setParent(xNode);
	xNode->setRight(yNode);
	yNode->setLeft(T3);
	T3->setParent(yNode);
	this->LeftLeft(zNode,xNode,yNode);
}

template<typename Key, typename Value>
void AVLTree<Key,Value>::LeftRight(AVLNode<Key,Value> *zNode,AVLNode<Key,Value> *yNode,AVLNode<Key,Value> *xNode){
	AVLNode<Key,Value> *T2 = xNode->getRight();
	zNode->setLeft(xNode);
	xNode->setParent(zNode);
	xNode->setLeft(yNode);
	yNode->setParent(xNode);
	yNode->setRight(T2);
	T2->setParent(yNode);
	this->RightRight(zNode,xNode,yNode);
}

template<typename Key, typename Value>
void AVLTree<Key,Value>::RightRight(AVLNode<Key,Value> *zNode,AVLNode<Key,Value> *yNode,AVLNode<Key,Value> *xNode){
	AVLNode<Key,Value> *T2 = yNode->getLeft();
	if(zNode == zNode->getParent->getRight()){
		zNode->getParent()->setRight(yNode);
	}else{
		zNode->getParent()->setLeft(yNode);
	}
	zNode->setParent(yNode);
	zNode->setRight(T2);
	yNode->setLeft(zNode);
	T2->setParent(zNode);
}

/**
* Remove function for a given key. Finds the node, reattaches pointers, and then balances when finished. 
*/

template<typename Key, typename Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
	// TODO
}

/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif
