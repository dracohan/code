package main

import (
	"fmt"
)

func main() {
	s := make([]int, 0, 10)
	for i := 41; i > 0; i-- {
		s = append(s, i)
		fmt.Println(len(s))
		fmt.Println(cap(s))
	}
}
