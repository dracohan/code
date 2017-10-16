package main

import (
	"book/GoDS/4_tree/avltree"
	"fmt"
)

func main() {
	avlt := avltree.NewWithIntComparator()
	avlt.Insert(4)
	avlt.Insert(3)
	avlt.Insert(6)
	avlt.Insert(0)
	avlt.Insert(2)
	avlt.Insert(3)
	avlt.PrintTree()
	fmt.Println(avlt.Contains(3))
	fmt.Println(avlt.FindMax())
	fmt.Println(avlt.FindMin())
	avlt.Remove(3)
	avlt.PrintTree()
}
