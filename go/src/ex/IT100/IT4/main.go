package main

import (
	stack "book/GoDS/stack/arraystack"
	"fmt"
)

var path *stack.Stack
var curSum int

type tree struct {
	value       int
	left, right *tree
}

func insert(t *tree, n int) *tree {
	if t == nil {
		return &tree{value: n}
	}

	if n < t.value {
		t.left = insert(t.left, n)
	} else if n > t.value {
		t.right = insert(t.right, n)
	} else {
		//ignore
	}

	return t
}

func findPath(t *tree, sum int) {
	if t == nil {
		return
	}

	curSum += t.value
	path.Push(t.value)

	isLeaf := (t.left == nil && t.right == nil)

	if isLeaf && curSum == sum {
		fmt.Println(path.String())
	}

	if t.left != nil {
		findPath(t.left, sum)
	}
	if t.right != nil {
		findPath(t.right, sum)
	}

	curSum -= t.value
	path.Pop()
}

func main() {
	var t *tree
	path = stack.New()
	a := []int{14, 5, 16, 3, 11, 10, 15, 30}
	for _, n := range a {
		t = insert(t, n)
	}
	findPath(t, 45)
}
