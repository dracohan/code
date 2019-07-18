package main

import (
	"fmt"
)

func main() {
	fmt.Println("create a slice and add/delete/query items")
	s := []int{3, 1, 2, 3, 4, 5, 6, 0}
	append(s, 111)
	fmt.Println(s)
}
