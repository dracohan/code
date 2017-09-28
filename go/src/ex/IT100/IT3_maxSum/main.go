package main

import (
	"fmt"
)

func main() {
	var sum, maxSum int
	t := []int{1, -2, 3, 10, -4, 7, 2, -5}
	for i := 0; i < len(t); i++ {
		sum = sum + t[i]

		if sum < 0 {
			sum = 0
		}

		if sum > maxSum {
			maxSum = sum
		}
	}
	fmt.Println(maxSum)
}
