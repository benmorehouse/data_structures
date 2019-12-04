#include "bst.h"
#include "avlbst.h"
#include <iostream>

int main(){
	BinarySearchTree<int,int> *bst = new BinarySearchTree<int,int>();
	bst->clear();
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
}
