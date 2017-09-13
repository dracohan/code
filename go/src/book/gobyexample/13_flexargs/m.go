package main

import (
	"fmt"
)

func sum(a ...int) int {
	var sum int
	for _, n := range a {
		sum += n
	}
	return sum
}

func main() {
	fmt.Println(sum(1, 2))
	fmt.Println(sum(1, 2, 3))
	nums := []int{1, 2, 3, 4}
	fmt.Println(sum(nums...))
}
