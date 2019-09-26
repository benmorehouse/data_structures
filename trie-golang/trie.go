package main

import "fmt"

type trie struct{
	root *node
}

func (tree *trie) insert(word string){
	current := tree.root

	for _ , character := range word{
		fmt.Println(current.children)
		fmt.Println("test")
		exists, index := check_if_character_exists(byte(character),current.children)// this is breaking
		if exists{
			counterTemp := current.counter
			*current = current.children[index]
			current.counter = counterTemp
			current.counter++
		}else{
			var new_node = node{character:byte(character)}
			current.children = append(current.children, new_node)
			*current = new_node
			current.counter++
		}
	}
	current.word_finished = true
	return
}

func (tree *trie) search(word string)(bool){
	if tree.root == nil{
		return false
	}
	current := tree.root
	for _ , character := range word{
		exists, index := check_if_character_exists(byte(character), current.children)
		if !exists{
			return false
		}else{
			*current = current.children[index]
		}
	}
	if current.word_finished{
		return true
	}else{
		return false
	}
}

func check_if_character_exists(input byte, children_nodes []node)(bool,int){
	var characters []byte
	for _ , chars := range children_nodes{
		childchar := chars.character
		characters = append(characters,childchar)
	}
	// at this point characters is what we want
	for i , val := range characters{
		if input == val{
			return true, i
		}else{
			continue
		}
	}
	return false, -1
}


