package main

import(
	"errors"
)

type trie struct{
	root node
}

func (tree *trie) insert(word string){
	current := tree.root
	for _ , character := range word{
		exists, index := check_if_character_exists(character,current.children)
		if exists{
			current = current.children[index]
			current.count++
		}else{
			var new_node = node{character:character}
			current.children = append(current.children, character)
			current = new_node
			current.counter++
		}
	}
	current.word_finished = true
	return
}

func (tree *trie) search(word string)(error){
	if tree.root == nil{
		return errors.New("Error: trie is completely empty")
	}
	current := tree.root
	for _ , character := range word{
		exists, index := check_if_character_exists(character, current.children)
		if !exists{
			err := errors.New("Error: string not found")
			return err
		}else{
			current = current.children[index]
		}
	}
	if current.word_finished{
		return nil
	}else{
		return errors.New("Word not found")
	}
}

func check_if_character_exists(input byte, characters []byte)(bool,int){
	for i , val := range chacters{
		if input == val{
			return true, i
		}else{
			continue
		}
	}
	return false, -1
}


