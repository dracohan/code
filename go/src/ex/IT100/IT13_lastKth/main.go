package main

import (
	"fmt"
)

type node struct {
	next *node
	data int
}

func add(head *node, data int) *node {
	p := &node{head, data}
	head = p
	return head
}

func findKth(node *node, n int) *node {
	p := node
	for i := 0; i < n; i++ {
		p = p.next
	}
	k := node
	for p.next != nil {
		p = p.next
		k = k.next
	}
	return k
}

func main() {
	var head *node
	for i := 10; i > 0; i-- {
		head = add(head, i)
	}

	p := findKth(head, 4)
	fmt.Println(p.data)
}
