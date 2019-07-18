package main

import (
	"fmt"
)

type T struct {
	a, b int
}

func main() {
	fmt.Println("create struct and print it")
	t := T{1, 2}
	s := T{1, 2}
	fmt.Println(t == s)
}
