package main

import (
	"fmt"
)

type color byte

func main() {
	fmt.Println("start")
	const (
		a = iota
		b
		c
		d = 1
		e
	)
	fmt.Println(b, c, e)

	const (
		black color = iota
		red
		blue
	)
	test(red)
	test(100)

	// x := 2
	// test(x)

	x := 2
	// const y = 3
	fmt.Println(&x)
	// fmt.Println(&y)
}

func test(c color) {
	println(c)
}
