package main

import (
	"fmt"
)

func main() {
	fmt.Println("start")
	type s struct {
		a int
	}
	i := s{}
	i.a = 100

	p := &i
	p.a += 1
	fmt.Println(i.a)

	fmt.Println(p)

	var q *int
	var qq *int
	fmt.Println(qq == q)
}
