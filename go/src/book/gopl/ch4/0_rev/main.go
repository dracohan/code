package main

import (
	"fmt"
)

func rev(a []int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func main() {
	s := [...]int{1, 2, 3, 4, 5, 6, 7}
	rev(s[:])
	for _, r := range s {
		fmt.Printf("%d ", r)
	}
	i := 1
	i++
	fmt.Println(i)
}