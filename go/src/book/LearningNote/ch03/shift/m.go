package main

import (
	"fmt"
)

func main() {
	const (
		d byte = 2 << iota
		b
		c
	)
	fmt.Println("start")
	a := 3
	fmt.Println(a << 3)
	fmt.Println(b)
	fmt.Println(c)
}
