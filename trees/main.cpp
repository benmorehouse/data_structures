#include "bst.h"
#include "avlbst.h"
#include <iostream>

int main(){
	BinarySearchTree<int,int> *bst = new BinarySearchTree<int,int>();
	const std::pair<int,int>firstInsert(1,1);
	const std::pair<int,int>secondInsert(2,2);
	const std::pair<int,int>thirdInsert(3,3);
	const std::pair<int,int>fourthInsert(4,4);
	const std::pair<int,int>fifthInsert(5,5);
	bst->insert(thirdInsert);
	bst->insert(fourthInsert);
	bst->insert(fifthInsert);
	bst->insert(firstInsert);
	bst->insert(secondInsert);
	bst->print();
	bst->clear();
	bst->insert(thirdInsert);
	bst->insert(fourthInsert);
	bst->insert(fifthInsert);
	bst->insert(firstInsert);
	bst->insert(secondInsert);
	bst->print();

/*
	AVLTree<int,int> *avl = new AVLTree<int,int>();
	const std::pair<int,int>firstInsert(1,1);
	const std::pair<int,int>secondInsert(2,2);
	const std::pair<int,int>thirdInsert(3,3);
	const std::pair<int,int>fourthInsert(4,4);
	const std::pair<int,int>fifthInsert(5,5);
	const std::pair<int,int>sixthInsert(6,6);
	const std::pair<int,int>seventhInsert(7,6);
	const std::pair<int,int>zeroInsert(0,6);
	const std::pair<int,int>negativeInsert(-1,6);
	const std::pair<int,int>negativethreeInsert(-3,6);
	const std::pair<int,int>negativetwoInsert(-2,6);

	avl->insert(firstInsert);
	avl->insert(secondInsert);
	avl->insert(thirdInsert);
	avl->insert(fourthInsert);
	avl->insert(fifthInsert);
	avl->insert(zeroInsert);
	avl->insert(negativeInsert);
	avl->insert(negativetwoInsert);
	avl->insert(seventhInsert);
	avl->insert(sixthInsert);
	avl->remove(2);
	avl->remove(3); 
	avl->print();

*/
	/*
	 * Things broken with AVL remove: When you add above sequence then delete 2, then 3, right subtree is incorrect.
	*/
}
