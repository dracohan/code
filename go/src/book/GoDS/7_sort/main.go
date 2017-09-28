package main

import (
	"fmt"
)

func main() {
	sep := ","
	t := []int{9, 3, 4, 5, 1, 6, 8, 2, 12, 14, 22, 18, 3, 11}
	//	t := []int{9, 1, 2, 3, 4, 5, 6, 7, 8}
	//	bubbleSort(t)
	//	insertionSort(t)
	//	shellsort(t)
	//	mergesort(t)
	QuickSort(t)
	for i, n := range t {
		if i == len(t)-1 {
			sep = ""
		}
		fmt.Printf("%d%s ", n, sep)
	}
}
