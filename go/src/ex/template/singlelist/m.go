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

func main() {
	fmt.Println("create a list and print it...")
	var head, n *node
	for i := 0; i < 10; i++ {
		head = add(head, i)
	}
	for n = head; n.next != nil; n = n.next {
		fmt.Print(n.data, " ")
	}
	fmt.Println(n.data)
}
