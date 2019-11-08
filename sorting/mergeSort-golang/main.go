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
	divide(array, 0, len(array)-1)
	fmt.Println(array)
}

func divide(array []int, left int, right int){
	if(left < right){
		split := (left + right)/2 //this means that the split will be at 
		divide(array, left, split)
		divide(array, split+1, right)
		merge(array, left, split, right) // array is marked where left is [left...m]
	}
}

func merge(array []int, left, m, right int){
	Lsize := m - left + 1
	Rsize := right - m
	var L []int // the left array we feed into
	var R []int // the right array we feed into

	for i:=0;i<Lsize;i++{
		L[i] = array[left+i]
	}
	for i:=0;i<Rsize;i++{
		R[i] = array[m+i]
	}

	i := 0
	j := 0

	var newArray []int
	for i<Lsize && j<Rsize{
		if L[i] < R[j]{
			newArray = append(newArray,L[i])
			i++
		}else{
			newArray = append(newArray,L[i])
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

	return
}

