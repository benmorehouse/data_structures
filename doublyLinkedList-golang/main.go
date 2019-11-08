package main

import(
	"fmt"
	"log"
	"errors"
)

type node struct{
	Prev *node
	Next *node
	Data int
}

func createNode(data int)*node{
	var newNode = node{
		Prev: nil,
		Next: nil,
		Data: data,
	}
	return newNode
}

type doublyLinkedList struct{
	Head *node
	Tail *node
	Size int
}

func init()(*doublyLinkedList){
	var list = doubleLinkedList{
		Head: nil,
		Tail: nil,
		Size: 0,
	}
	return list
}

func (this *doublyLinkedList) Append(input int)error{
	if this == nil{
		return errors.New("Entered list is nil")
	}
	if this.Head == nil{
		newNode := createNode(input)
		this.Head = newNode
		this.Tail = newNode
		size++
		return nil
	}else{
		newNode := createNode(input)
		this.Tail.Next = newNode
		newNode.Prev = this.Tail
		this.Tail = newNode
		return nil
	}
}

func (this *doubleLinkedList) Delete(input int) error{
	if this == nil{
		return errors.New("Entered list is nil")
	}

	if this.Head == nil{
		return errors.New("Entered list is empty")
	}else if this.Head == this.Tail{
		this.Head = nil
		this.Tail = nil
		return nil
	}else{
		current := this.Head
		for current != nil{
			if current.Data == input{
				current.Prev.Next = current.Next
				current.Next.Prev = current.Prev
				return nil
			}
		}
		return errors.New("couldnt find the data")
	}
}

func main(){
	fmt.Println("")
}


