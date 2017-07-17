package main

import (
	"fmt"
)

type I interface {
	boo()
}

type S struct {
	name string
	age  int
}

func (s S) boo() {
	fmt.Println("boo()")
}

func main() {
	fmt.Println("---------start----------")
	s := S{}
	var i I
	i = s
	i.boo()
	var ss []int = []int{1, 2, 3, 7}
	var ss1 []int = make([]int, 0, 5)
	fmt.Println(len(ss))
	fmt.Println(len(ss1))

	fmt.Println("---------end----------")
}
