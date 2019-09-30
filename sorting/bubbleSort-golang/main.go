package main

import(
	"fmt"
	"log"
	"errors"
)

func bubbleSort(array []int)(error){
	if len(array) == 0{
		return errors.New("Empty array")
	}

	sorted := false

	for !sorted{
		sorted = true
		for i:=0;i<len(array)-2;i++{
			if array[i+1] < array[i]{
				array[i+1], array[i] = array[i],array[i+1]
				sorted = false
			}
		}
	}

	return nil
}

func main(){
	var array = []int{1,0,4,3,8,10}
	err := bubbleSort(array)
	if err != nil{
		log.Println(err)
	}
	fmt.Println(array)
}


/*
this algorithm is better because with selection sort, we 
always know that its gonna be o(n) something

so that we have at least the possibility of 
