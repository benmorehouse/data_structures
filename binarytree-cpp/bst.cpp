#include "bst.h"
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

// the key pretty much acts as the value... thus we must assess
//Helper functions?
bool Node::isBST(Node *root) {
	// what are the cases... 
	// either no children
	// only a right child
	// only left child
	// or both children
	return isBSTHelper(root, root->key, root->key);
}

bool Node::isBSTHelper(Node* root, int minRange, int maxRange){
	if(root->left == nullptr && root->right == nullptr){
		return true;
	}else if(root->left == nullptr && root->right != nullptr){
		if(root->right->key >= root->key){
			if (root->right->key > maxRange){
				return false;
			}else{
				return isBSTHelper(root->right, root->key, maxRange);
			}
		}else{
			return false;
		}
	}else if(root->left != nullptr && root->right == nullptr){
		if(root->left->key <= root->key){
			if (root->left->key < minRange){
				return false;
			}else{
				return isBSTHelper(root->right, minRange, root->key);
			}
		}else{
			return false;
		}
	}else{
		if(root->left->key <= root->key && root->right->key >= root->key){
			if (root->left->key < minRange){
				return false;
			}else if(root->right->key > maxRange){
				return false;
			}else{
				return isBSTHelper(root->left, minRange, root->key) && isBSTHelper(root->right, root->key, maxRange);
			}
		}else{
			return false;
		}
	}
}
//Helper functions?
// need to recursively call down. Then return the height back up
bool Node::isBalanced(Node *root) {
	if(root->left == nullptr && root->right == nullptr){
		return true;
	}else if(root->left == nullptr && root->right != nullptr){
		return getHeight(root->right) <= 1;
	}else if(root->left != nullptr && root->right == nullptr){
		return getHeight(root->left) <= 1;
	}else{
		return abs(getHeight(root->left) - getHeight(root->right)) <= 1;
	}
}

int Node::getHeight(Node *root){
	if(root == nullptr){
		return 0;
	}else{
		return 1 + std::max(getHeight(root->right),getHeight(root->left));
	}
}

