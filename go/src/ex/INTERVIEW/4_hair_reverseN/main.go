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
	fmt.Printf("%d\n", p.data)
}

func reverseN(head *node, num int) *node {
	var prev, curr, next *node
	var count int

	if num == 0 || num == 1 {
		return head
	}

	prev = head
	curr = prev.next

	for num-1 > count {
		if curr != nil {
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next
			count++
		} else {
			curr = prev.next //前一个元素
			prev.next = nil
			for count > 0 {
				next = curr.next
				curr.next = prev //矫正
				prev = curr
				curr = next
				count--
			}
			return prev
		}
	}
	if next != nil {
		head.next = reverseN(next, num) //当前head的下一个指向下一次递归的新head
	} else {
		head.next = nil
	}
	return prev //返回每一段的新head
}

func main() {
	var head *node
	for i := 11; i > 0; i-- {
		head = add(head, i)
	}
	printList(head)
	head = reverseN(head, 3)
	printList(head)
}
