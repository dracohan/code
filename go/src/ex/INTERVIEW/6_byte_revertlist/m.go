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
	//不存下来无法识别原来的表头
	if phead == nil {
		phead = head
	}
	if head.next == nil {
		nhead = head
		return head
	}
	rev(head.next).next = head
	//不设置原表头的next会循环指向
	if phead.next != nil {
		phead.next = nil
	}
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
