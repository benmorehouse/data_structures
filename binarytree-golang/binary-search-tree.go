package main

import(
	"errors"
)

type node struct{
	Data int
	Right *node
	Left *node
}

func (head *node) Insert(input int)error{
	if head == nil{
		return errors.New("Root node is nil")
	}

	if input < head.Data{
		if head.Left != nil{
			return head.Left.Insert(input)
		}else{
			var newNode = node{
				Data: input,
				Right: nil,
				Left: nil,
			}

			head.Left = &newNode
			return nil
		}
	}else if input >= head.Data{
		if head.Right != nil{
			return head.Right.Insert(input)
		}else{
			var newNode = node{
				Data: input,
				Right: nil,
				Left: nil,
			}

			head.Right = &newNode
			return nil
		}
	}

	return errors.New("Something wrong with Insert function")
}

func (head *node) Search(input int) error{
	if head == nil{
		return errors.New("Root node is nil")
	}

	if input < head.Data{
		if head.Left != nil{
			return head.Left.Search(input)
		}else{
			return errors.New("Node doesnt exists")
		}
	}else if input > head.Data{
		if head.Right != nil{
			return head.Right.Search(input)
		}else{
			return errors.New("Node doesnt exists")
		}
	}else{
		return nil
	}
	return errors.New("Something wrong with search function")
}

func (head *node) BFS(input int)error{
	var queue []*node
	if head == nil{
		return errors.New("Entered an empty node")
	}else if head.Data == input{
		head.Data == input{
		return nil
	}

	if head.Right == nil{
		queue = append(queue, head.Left)
	}else if head.Left == nil{
		queue = append(queue, head.Right)
	}else{
		queue = append(queue, head.Left)
		queue = append(queue, head.Right)
	}
	return BFSHelper(input, queue)
}

func BFSHelper(input int, queue []*node) error{
	var newQueue []*node
	if len(queue) == 0{
		return errors.New("couldnt find the node")
	}
	for i:=0;i<len(queue);i++{
		if queue[i].Data == input{
			return nil
		}else{
			if queue[i].Right == nil && queue[i].Left == nil{
				continue
			}else if queue[i].Right == nil{
				newQueue = append(newQueue, queue[i].Left)
			}else if queue[i].Left == nil{
				newQueue = append(newQueue, queue[i].Right)
			}else{
				newQueue = append(newQueue, queue[i].Left)
				newQueue = append(newQueue, queue[i].Right)
			}
		}
	}
	return BFSHelper(input, newQueue)
}

func (head *node) DFS(input int)error{
	if head == nil{
		return errors.New("Entered an empty node")
	}else if head.Data == input{
		return nil
	}

	var stack []*node
	stack = append(stack, head)
	c := make[chan bool, 2] // using a buffered channel so we dont get more than two pushes through the channel

	currentProcesses := 0
	if head.Right != nil{
		currentProcesses++
		go DFSHelper(input, append(stack, head.Right), c)
	}

	if head.Left != nil{
		currentProcesses++
		go DFSHelper(input, append(stack, head.Left), c)
	}

	for len(c) != currentProcesses{
		select{
		case c <- false:
			fmt.Println("Found one of the children to be false")
		case c <- true:
			fmt.Println("Found one of the children to be false")
			return nil
		default:
			continue
		}
	}

	return errors.New("Node not found")

}

func DFSHelper(input int, stack []*node, done chan bool){
	if stack[len(stack)-1].Data == input{
		done <- true
		return
	}else{

		if stack[len(stack)-1].Left != nil{
			stack = append(stack,stack[len(stack)-1].Left)
			DFSHelper(input, stack
		}





}
