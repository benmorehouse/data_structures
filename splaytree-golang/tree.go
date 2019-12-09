package main

import(
	"math"
)

type splayTree struct{
	BadInserts int // used to tell if we are having some sort of bad input
	Steps int
	Size int
	Root *node
}

func (this* splayTree) init(){
	this.BadInserts = 0
	this.Steps = 0
	this.Root = nil
}

func (this* splayTree) insert(input int){
	var newNode *node
	newNode.data = input
	this.Size++
	newNode = this.binaryTreeInsert(newNode)
	this.SplayUp(newNode)
	// then we need to do a binary insert into the tree
}

func (this* splayTree) binaryTreeInsert(newNode *node)(*node){
	if this.Root == nil{
		this.Root = newNode
		return this.Root
	}

	currentNode := this.Root
	for currentNode != nil{
		if newNode.data < currentNode.data{
			if currentNode.leftChild == nil{
				currentNode.leftChild = newNode
				newNode.parent = currentNode
				return currentNode.leftChild
			}
			currentNode = currentNode.leftChild
			continue
		}else if newNode.data > currentNode.data{
			if currentNode.rightChild == nil{
				currentNode.rightChild = newNode
				newNode.parent = currentNode
				return currentNode.rightChild
			}
			currentNode = currentNode.rightChild
			continue
		}else{
			return currentNode
		}
	}
	return nil
}

func (this* splayTree) SplayUp(newNode *node){
	// this means we now need to splay to the root
	if newNode == this.Root{
		return
	}
	var InsertionCost float64
	InsertionCost = 0
	for newNode != this.Root{
		if newNode.parent == this.Root{
			if newNode.parent.rightChild == newNode{
				zNode := newNode.parent
				yNode := newNode
				xNode := newNode.rightChild
				this.LeftRotation(zNode,yNode,xNode)
			}else{
				zNode := newNode.parent
				yNode := newNode
				xNode := newNode.leftChild
				this.RightRotation(zNode,yNode,xNode)
			}
			InsertionCost++
		}else{
			parent := newNode.parent
			if parent.leftChild == newNode && parent.parent.leftChild == parent{
				// this is a left left case
				zNode := parent
				yNode := newNode
				xNode := newNode.leftChild
				this.RightRotation(zNode,yNode,xNode)
				InsertionCost++
				this.RightRotation(yNode,xNode,xNode.leftChild)
				InsertionCost++
			}else if parent.leftChild == newNode && parent.parent.rightChild == parent{
				// this is a left right case
				zNode := parent
				yNode := newNode
				xNode := newNode.rightChild
				this.LeftRotation(zNode,yNode,xNode)
				this.Steps++
				this.RightRotation(yNode.parent,yNode,zNode)
				InsertionCost++
			}else if parent.rightChild == newNode && parent.parent.rightChild == parent{
				// this is a right right case
				zNode := parent
				yNode := newNode
				xNode := newNode.rightChild
				this.LeftRotation(zNode,yNode,xNode)
				InsertionCost++
				this.LeftRotation(yNode,xNode,xNode.rightChild)
				InsertionCost++
			}else{
				// and the final case: right left
				zNode := parent
				yNode := newNode
				xNode := newNode.leftChild
				this.RightRotation(zNode,yNode,xNode)
				this.Steps++
				this.LeftRotation(yNode.parent,yNode,zNode)
				InsertionCost++
			}
		}
	}

	if InsertionCost > 2*math.Log2(float64(this.Size)){
		this.BadInserts++
	}
}

func (this* splayTree) RightRotation(zNode *node, yNode *node, xNode *node){
	T := yNode.rightChild
	if zNode == this.Root{
		this.Root = yNode
	}else{
		if zNode.parent.leftChild == zNode{
			zNode.parent.leftChild = yNode
		}else{
			zNode.parent.rightChild = yNode
		}
	}
	yNode.parent = zNode.parent
	yNode.rightChild = zNode
	zNode.parent = yNode
	zNode.leftChild = T
	if T != nil{
		T.parent = zNode
	}
}

func (this* splayTree) LeftRotation(zNode *node, yNode *node, xNode *node){
	T := yNode.leftChild
	if zNode == this.Root{
		this.Root = yNode
	}else{
		if zNode.parent.leftChild == zNode{
			zNode.parent.leftChild = yNode
		}else{
			zNode.parent.rightChild = yNode
		}
	}
	yNode.parent = zNode.parent
	yNode.leftChild = zNode
	zNode.parent = yNode
	zNode.rightChild = T
	if T != nil{
		T.parent = zNode
	}
}







