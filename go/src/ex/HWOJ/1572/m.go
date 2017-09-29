package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	ErrorOutofBound = errors.New("array index out of bound")
)

const (
	ERROR_GET = iota
	ERROR_SET
	ERROR_REMOVE
)

type Node struct {
	data int
	prev *Node
	next *Node
}

func NewNode(x int, p *Node, n *Node) *Node {
	return &Node{data: x, prev: p, next: n}
}

type LinkedList struct {
	theSize     int
	beginMarker *Node
	endMarker   *Node
}

func NewLinkedList() *LinkedList {
	ll := &LinkedList{0, nil, nil}
	return ll.init()
}

func (ll *LinkedList) init() *LinkedList {
	ll.beginMarker = NewNode(0, nil, nil)
	ll.endMarker = NewNode(0, ll.beginMarker, nil)
	ll.beginMarker.next = ll.endMarker

	ll.theSize = 0
	return ll
}

func (ll *LinkedList) Size() int {
	return ll.theSize
}

func (ll *LinkedList) IsEmpty() bool {
	return ll.theSize == 0
}

func (ll *LinkedList) AddByValue(n int) {
	var p *Node
	p = ll.beginMarker.next
	for p != ll.endMarker && p.data < n {
		p = p.next
	}
	newNode := NewNode(n, p.prev, p)
	newNode.prev.next = newNode
	p.prev = newNode
	ll.theSize++

}

func (ll *LinkedList) Add(n int) {
	ll.AddBefore(ll.theSize-1, n)
}

func (ll *LinkedList) AddBefore(idx, n int) {
	p, err := ll.GetNode(idx)
	if err != nil {
		ll.addBefore(p, n)
	}
}

func (ll *LinkedList) addBefore(p *Node, n int) {
	newNode := NewNode(n, p.prev, p)
	newNode.prev.next = newNode
	p.prev = newNode
	ll.theSize++
}

func (ll *LinkedList) Get(idx int) int {
	p, err := ll.GetNode(idx)
	if err != nil {
		return ERROR_GET
	}
	return p.data
}

func (ll *LinkedList) Set(idx, n int) int {
	p, err := ll.GetNode(idx)
	if err != nil {
		return ERROR_SET
	}
	oldvar := p.data
	p.data = n
	return oldvar
}

func (ll *LinkedList) RemoveByIdx(idx int) int {
	p, err := ll.GetNode(idx)
	if err != nil {
		return ERROR_REMOVE
	}
	return ll.remove(p)
}

func (ll *LinkedList) GetNode(idx int) (node *Node, err error) {
	return ll.getNode(idx, 0, ll.Size()-1)
}

func (ll *LinkedList) getNode(idx, lower, upper int) (node *Node, err error) {
	var p *Node

	if idx < lower || idx > upper {
		return nil, ErrorOutofBound
	}

	if idx < ll.Size()/2 {
		p = ll.beginMarker.next
		for i := 0; i < idx; i++ {
			p = p.next
		}
	} else {
		p = ll.endMarker
		for i := ll.Size(); i > idx; i-- {
			p = p.prev
		}
	}

	return p, nil
}

func (ll *LinkedList) remove(p *Node) int {
	p.prev.next = p.next
	p.next.prev = p.prev
	ll.theSize--
	return p.data
}

func (ll *LinkedList) PrintAll() {
	for p := ll.beginMarker.next; p.next != nil; p = p.next {
		if p.next == ll.endMarker {
			fmt.Println(p.data)
		} else {
			fmt.Printf("%d ", p.data)
		}

	}
}

func sort(str []string) {
	ll := NewLinkedList()
	for _, s := range str {
		n, _ := strconv.Atoi(s)
		ll.AddByValue(n)
	}
	ll.PrintAll()
}

func main() {
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		line := text.Text()
		s := strings.Split(line, " ")
		sort(s)
	}
}
