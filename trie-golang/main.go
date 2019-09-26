package main

import(
	"fmt"
)

func main(){
	fmt.Println("test")
	var data trie
	data.insert("hello")
	data.insert("hey")
	data.insert("hi")
	if data.search("hello") == true{
		fmt.Println("its in there")
	}else{
		fmt.Println("Its not in there")
	}
}

