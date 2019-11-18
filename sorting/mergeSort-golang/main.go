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
	divide(array, 0, len(array)-1)
	fmt.Println(array)
}

func divide(array []int, left int, right int){
	if(left < right){
		split := (left + (right-1))/2 //this means that the split will be at 
		divide(array, left, split)
		divide(array, split+1, right)
		fmt.Println("Calling merge with left=",left," and split=",split," and right=",right)
		merge(array, left, split, right) // array is marked where left is [left...m]
	}
}

func merge(array []int, left, m, right int){
	Lsize := m - left + 1
	Rsize := right - m
	var L []int // the left array we feed into
	var R []int // the right array we feed into

	for i:=0;i<Lsize;i++{
		L = append(L,array[left+i])
	}

	fmt.Println("L is:",L)

	for i:=0;i<Rsize;i++{
		R = append(R,array[m+i+1])
	}

	fmt.Println("R is:",R)

	i := 0
	j := 0

	var newArray []int
	for i<Lsize && j<Rsize{
		if L[i] < R[j]{
			newArray = append(newArray,L[i])
			i++
		}else{
			newArray = append(newArray,R[j])
			j++
		}
	}

	for i<Lsize{
		newArray = append(newArray, L[i])
		i++
	}

	for j<Rsize{
		newArray = append(newArray, R[j])
		j++
	}

	fmt.Println("newarray is:",newArray)
	array = newArray
	return
}

