package main

import (
	"fmt"
)

func verify(a []int, size int) bool {
	if size == 1 {
		return true
	}
	if a == nil || size == 0 {
		return false
	}

	root := a[size-1]
	var i, j int
	for i = 0; a[i] < root; i++ {
	}

	for j = i; j < size-1; j++ {
		if a[j] < root {
			return false
		}
	}

	left := verify(a[0:i], i)
	right := verify(a[i:], size-i-1)
	return left && right
}

func main() {
	t := []int{4, 8, 6, 12, 16, 14, 10}
	r := verify(t, 7)
	fmt.Println(r)
}
