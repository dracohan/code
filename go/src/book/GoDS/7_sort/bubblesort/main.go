package main

import (
	"fmt"
)

func bubbleSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-1-i; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

func main() {
	t := []int{4, 3, 5, 6, 7, 12, 1}
	bubbleSort(t)
	for _, n := range t {
		fmt.Printf("%d, ", n)
	}
}
