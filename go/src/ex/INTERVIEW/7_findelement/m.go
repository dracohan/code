package main

import (
	"fmt"
)

func contains(x int, arr []int) bool {
	for _, n := range arr {
		if n == x {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println("start")
	same := make(map[int]int)
	diff := make(map[int]int)
	arr1 := []int{1, 2, 4, 5, 7}
	arr2 := []int{-1, 2, 3, 6, 7}

	for _, n1 := range arr1 {
		if contains(n1, arr2) {
			same[n1]++
		} else {
			diff[n1]++
		}
	}

	for _, n2 := range arr2 {
		if !contains(n2, arr1) {
			diff[n2]++
		}
	}

	fmt.Println("same:", same)
	fmt.Println("diff:", diff)
}
