package main

import (
	"fmt"
)

var head, last *tree

type tree struct {
	value       int
	right, left *tree
	prev, next  *tree
}

func insert(t *tree, value int) *tree {
	if t == nil {
		return &tree{value: value}
	}
	if t.value > value {
		t.left = insert(t.left, value)
	} else if t.value < value {
		t.right = insert(t.right, value)
	} else {
		//ignore duplicate
	}
	return t
}

func (t *tree) treeToList() {
	if nil == t {
		return
	}
	t.left.treeToList()

	if last == nil {
		head = t
	} else {
		t.prev = last
		last.next = t
	}
	last = t

	t.right.treeToList()

}

func printList(t *tree) {
	if nil == t {
		return
	}
	for t.next != nil {
		fmt.Println(t.value)
		t = t.next
	}
	fmt.Println(t.value)
}

func main() {
	ta := []int{10, 6, 14, 4, 4, 8, 12, 16}

	var t *tree
	for _, n := range ta {
		t = insert(t, n)
	}
	t.treeToList()
	printList(head)
}
