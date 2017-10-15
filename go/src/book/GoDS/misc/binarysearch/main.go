// binarysearch project main.go
package main

import (
	"fmt"
)

func binarySearch(n int, v []int) int {
	low := 0
	high := len(v) - 1
	for low <= high {
		mid := (low + high) / 2

		if v[mid] < n {
			low = mid + 1
		} else if v[mid] > n {
			high = mid - 1
		} else {
			return mid
		}
	}

	return -1
}

func main() {
	v := []int{22, 33, 44, 55, 66, 77, 89, 99}
	fmt.Println("index is:", binarySearch(88, v))
}
