package main

import(
	"fmt"
)

func main(){
	var root = node{
		Data:0,
		Right: nil,
		Left: nil,
	}
	root.Insert(1)
	root.Insert(3)
	root.Insert(-1)
	root.Insert(-3)
	fmt.Println(root.Right.Data)
	fmt.Println(root.Right.Right.Data)
	fmt.Println(root.Left.Data)
	fmt.Println(root.Left.Left.Data)
	fmt.Println(root.BFS(3))
}

