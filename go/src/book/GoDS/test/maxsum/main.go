package main

import (
	"fmt"
)

func getMaxSum(v []int) int {
	maxSum := 0
	thisSum := 0

	for _, i := range v {
		thisSum += i

		if thisSum > maxSum {
			maxSum = thisSum
		} else if thisSum < 0 { //只要是正的就留着
			thisSum = 0
		}
	}

	return maxSum
}

func main() {
	v := []int{2, 3, 1, -1, 3, -4, 5}
	fmt.Println("Max sum is:", getMaxSum(v))
}
