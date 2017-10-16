package main

import (
	"book/GoDS/4_tree/bstree"
)

func main() {
	bst := bstree.New()
	bst.Insert(4)
	bst.Insert(3)
	bst.Insert(6)
	bst.Insert(0)
	bst.Insert(2)
	bst.Insert(3)
	bst.PrintTree()
	print("Contains 3: ", bst.Contains(3), "\n")
	print("Max: ", bst.FindMax(), "\n")
	print("Min: ", bst.FindMin(), "\n")
	print("Size: ", bst.Size(), "\n")
	bst.Remove(3)
	bst.PrintTree()
}
