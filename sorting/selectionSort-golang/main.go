package main

import(
	"fmt"
	"log"
	"errors"
)

func selectionSort(array []int)error{
	if len(array) == 0{
		return errors.New("Empty array")
	}else if len(array) == 1{
		return nil
	}else{
		for i:=0;i<len(array)-2;i++{
			for j:=i;j<len(array)-1;j++{
				if array[j] < array[i]{
					array[i],array[j] = array[j], array[i]
				}
			}
		}
	}
	return nil
}

func main(){
	var array = []int{1,0,4,3,8,10}
	err := selectionSort(array)
	if err != nil{
		log.Println(err)
	}
	fmt.Println(array)
}

