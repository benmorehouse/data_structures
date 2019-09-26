package main

type node struct{
	word_finished bool // is the current node with the names complete
	counter int // the length of the word
	children []node
	character byte
}
