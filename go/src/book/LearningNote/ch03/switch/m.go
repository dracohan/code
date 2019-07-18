package main

import (
	"fmt"
)

func main() {
	fmt.Println("start")
	a, b, c, x := 1, 2, 3, 2
	switch x {
	case a:
		fmt.Println("a")
	case b:
		fmt.Println("b")
	case c:
		fmt.Println("c")
	default:
		fmt.Println("others")

	}
}
