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

func printList(head *node) {
	var p *node
	for p = head; p.next != nil; p = p.next {
		fmt.Printf("%d->", p.data)
	}
	fmt.Printf("%d", p.data)
}
func main() {
	var head *node
	for i := 10; i > 0; i-- {
		head = add(head, i)
	}
	printList(head)
}
