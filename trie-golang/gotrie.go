package main

import(
	"github.com/golang-collections/collections/trie"
	"fmt"
)
/*
type Trie struct{
	*trie // Trie will inherit golang's trie class
}
*/

func main(){
	mytrie := trie.New()
	fmt.Println(mytrie)
	mytrie.Init()
	fmt.Println(mytrie.root)
	mytrie.Insert("two","two")
	mytrie.Insert("one","one")
	fmt.Println(mytrie.String())
	fmt.Println(mytrie.root)
}

/*
func (temp *Trie) autofill(input string)(string, error){
	if temp.size == 0{
		return "" , errors.New("Trie is empty, nothing to autofill")
	}
}
*/

