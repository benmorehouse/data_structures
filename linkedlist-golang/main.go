package main

import(
	"fmt"
	"errors"
	/*
	"log"
	"math/rand"
	"time"
	*/
)

type Node struct{
	Next *Node
	Data int
}

func (head *Node) Size() int{
	current := head
	count := 0
	for current != nil{
		current = current.Next
		count ++
	}
	return count
}

func (head *Node) Append(input int) *Node{
	newNode := Node{Next: nil, Data: input}
	current := head
	if current == nil{
		return &newNode
	}else{
		for current.Next != nil{
			current = current.Next
		}
		current.Next = &newNode
	}
	return head
}

func (head *Node) Print(){
	if head == nil{
		return
	}else{
		current := head
		for current != nil{
			fmt.Println(&current,": ",current.Data)
			current = current.Next
		}
	}
}
// this goes through and finds the node at the given index
func RemoveNode(head *Node, target int)(*Node , error){
	if target < 0{
		return head, errors.New("Target cant be less than 0")
	}else if target == 0{
		return head.Next, nil
	}else if target > head.Size()-1{
		return head, errors.New("Target is greater than max index")
	}else{
		current := head
		index := 0
		for current != nil{
			if index == target-1{
				if target == head.Size()-1{
					current.Next = nil
					return head, nil
				}else{
					current.Next = current.Next.Next
					return head , nil
				}
			}else{
				current = current.Next
				index++
			}
		}
		return head, errors.New("Internal error with RemoveNode")
	}
}

// this is exactly o(n) runtime because you go through every node in the list and hope for the best  
func Reverse(head *Node)(*Node, error){
	if head == nil{
		return nil, errors.New("List is empty");
	}

	var prev *Node
	var next *Node
	prev = nil
	next = nil

	for head != nil{
		next = head.Next
		head.Next = prev
		prev = head
		head = next
	}
	return prev, nil
	// if you return head, it will be nil everytime and wont have anything to point to 
}

func GetNode(head *Node, index int)(int, error){
	if head == nil{
		return -1, errors.New("List is empty");
	}else if index < 0{
		return -1, errors.New("entered index doesnt exists")
	}

	i := 0
	curr := head

	for i != index{
		curr = curr.Next
		i++
	}

	if curr == nil{
		return -1, errors.New("Entered index is larger than the list")
	}

	return curr.Data, nil
}

func GetNodeRecursiveHelper(cur *Node, curIndex , target int)(int,error){
	if cur == nil{
		return -1, errors.New("node not present")
	}
	if curIndex == target{
		if cur != nil{
			return cur.Data , nil
		}
	}
	curIndex++
	return GetNodeRecursiveHelper(cur.Next , curIndex, target)
}

func GetNodeRecursive(cur *Node,target int) (int, error){
	return GetNodeRecursiveHelper(cur,0,target)
}

func isPalindrome(head *Node)(bool){
	current := head
	var array []int
	for current != nil{
		array = append(array, current.Data)
		current = current.Next
	}

	if len(array) == 1{
		return true
	}else if len(array)==2{
		if array[0] == array[1]{
			return true
		}else{
			return false
		}
	}
	for i:=0;i<len(array)/2;i++{
		if array[i] != array[len(array)-1-i]{
			return false
		}
	}
	return true
}


func main(){
	/*var head *Node
	rand.Seed(time.Now().UTC().UnixNano())
	head = head.Append(rand.Intn(100))
	head = head.Append(rand.Intn(100))
	head = head.Append(rand.Intn(100))
	head = head.Append(rand.Intn(100))
	head = head.Append(rand.Intn(100))
	head.Print()
	fmt.Println("invoking the reverse linked list function")
	head ,err := Reverse(head)
	if err != nil{
		log.Fatal("reverse didnt work:",err)
	}
	head.Print()
	selectedData , err := GetNode(head, 2)
	if err != nil{
		log.Fatal(err)
	}
	fmt.Println(selectedData)
	selectedData, err = GetNodeRecursive(head, 2)
	fmt.Println(selectedData)
	fmt.Print
	*/
	var head *Node
	head = head.Append(1)
	head = head.Append(2)
	head = head.Append(3)
	head = head.Append(2)
	head = head.Append(1)
	fmt.Println(isPalindrome(head))
}

/*
Things to know about linked lists in go:
	If you try and delete the current linked list to "free up memory", you are not correct
	go has a really good garbage collector that is built in by those who made the language. 

	Something like a recursive call is nice for instance when we are doing an expensive 
	function, like adding a bunch of numbers. But for instance if you are only referencing around
	three pointers, it is very low cost and it is better to just iterate throguh something. 
	
	This is seen in the recursive and not recursive iterations that we have for getting the node
	the iterative definition is better because instead of making a whole stack call,
	we are just adding numbers and moving on. That shouldnt be osmehitnbg we bog down the stack for.

*/
