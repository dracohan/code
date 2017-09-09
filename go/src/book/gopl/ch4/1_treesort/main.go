package main

import (
	"fmt"
)

var resArr []int

type tree struct {
	value       int
	left, right *tree
}

func Sort(values []int) {
	var root *tree
	for _, v := range values {
		root = add(root, v)
	}
	resArr = appendvalues(resArr, root)
}

func appendvalues(values []int, t *tree) []int {
	if t != nil {
		resArr = appendvalues(resArr, t.left)
		resArr = append(resArr, t.value)
		resArr = appendvalues(resArr, t.right)
	}
	return resArr
}

func add(t *tree, value int) *tree {
	if t == nil {
		t = new(tree)
		t.value = value
		return t
	}
	if value < t.value {
		t.left = add(t.left, value)
	} else if value > t.value {
		t.right = add(t.right, value)
	} else {
		//dup
	}
	return t
}

func main() {
	testArr := []int{14, 2, 13, 11, 9, 2, 3, 4, 5, 8, 1, 2, 3}
	Sort(testArr)
	fmt.Println(resArr)
}
