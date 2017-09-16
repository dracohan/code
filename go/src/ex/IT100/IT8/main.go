package main

import (
	"fmt"
)

type node struct {
	data int
	next *node
}

type list struct {
	head *node
	tail *node
	size int
}

func New() *list {
	return &list{&node{-1, nil}, &node{-1, nil}, 0}
}

func (l *list) Size() int {
	return l.size
}

func (l *list) reverse() {
	var pre, cur, np *node

}

func main() {
	l := New()
	for i := 0; i < 8; i++ {
		l.Add(i)
	}
	fmt.Println(l.String())
	l.reverse()

}
