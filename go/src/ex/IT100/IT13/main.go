package main

import (
	"fmt"
)

type node struct {
	next *node
	data int
}

func add(head *node, data int) {
	p := &node{head, data}
	head = p
}

func findKth(node *node, n int) *node {
	var p *node
	var k *node
	p = node
	for i := 0; i < n; i++ {
		p = p.next
	}
	k = p
	for p.next != nil {
		p = p.next
		k = k.next
	}
	return k
}

func main() {
	var head *node
	for i := 10; i > 0; i-- {
		add(head, i)
	}

	p := findKth(head, 4)
	fmt.Println(p.data)
}
