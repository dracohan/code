package main

import (
	"fmt"
)

var nhead *node
var phead *node

type node struct {
	next *node
	data int
}

func add(head *node, data int) *node {
	n := &node{head, data}
	head = n
	return head
}

func prt(head *node) {
	for head.next != nil {
		fmt.Print(head.data, " ")
		head = head.next
	}
	fmt.Println(head.data)
}

func rev(head *node) *node {
	if head.next == nil {
		nhead = head
		return head
	}
	rev(head.next).next = head
	head.next = nil
	return head
}

func main() {
	var head *node
	for i := 10; i > 0; i-- {
		head = add(head, i)
	}
	prt(head)
	rev(head)
	prt(nhead)

}
