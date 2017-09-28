package main

import (
	"fmt"
)

type node struct {
	data        int
	right, left *node
}

func add(n *node, i int) *node {
	if n == nil {
		return &node{i, nil, nil}
	}
	if i > n.data {
		n.right = add(n.right, i)
	} else if i < n.data {
		n.left = add(n.left, i)
	} else {
		//dup
	}
	return n
}

func mirror(n *node) {
	n.left, n.right = n.right, n.left
	if n.left != nil {
		mirror(n.left)
	}
	if n.right != nil {
		mirror(n.right)
	}
}

func printtree(n *node) {
	if n.left != nil {
		printtree(n.left)
	}
	fmt.Println(n.data)
	if n.right != nil {
		printtree(n.right)
	}
}

func main() {
	var root *node
	t := []int{8, 10, 6, 9, 11, 5, 7}
	for _, x := range t {
		root = add(root, x)
	}
	printtree(root)
	mirror(root)
	printtree(root)
}
