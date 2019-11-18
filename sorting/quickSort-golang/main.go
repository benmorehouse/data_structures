package main

import(
	"fmt"
	"math/rand"
)

func main(){
	var array []int
	for i:=0;i<8;i++{
		array = append(array,rand.Intn(100))
	}
	fmt.Println(array)
	quickSort(
	fmt.Println(array)
}

func quickSort(array []int, left, right int){
	
}
