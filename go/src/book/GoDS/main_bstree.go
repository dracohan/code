package main

import (
	"study/datastruct/tree/bstree"
)

func main_bstree() {
	bst := bstree.New()
	bst.Insert(4)
	bst.Insert(3)
	bst.Insert(6)
	bst.Insert(0)
	bst.Insert(2)
	bst.Insert(3)
	print("Contains 3: ", bst.Contains(3), "\n")
	print("Max: ", bst.FindMax(), "\n")
	print("Min: ", bst.FindMin(), "\n")
	print("Size: ", bst.Size(), "\n")
	bst.Remove(3)
	bst.PrintTree()
}
