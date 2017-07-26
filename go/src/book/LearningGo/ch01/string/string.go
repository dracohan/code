package main

import (
	"fmt"
)

func main() {
	fmt.Println("-----------------")
	var s string = "hello"
	var c []rune = []rune(s)
	c[0] = 'c'
	fmt.Println(c)
	fmt.Println("-----------------")
}
