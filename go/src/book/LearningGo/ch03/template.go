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

// func main() {
// 	fmt.Println("---------start----------")
// 	s := S{}
// 	var i I
// 	i = s
// 	i.boo()

// 	v := new([]int)
// 	fmt.Printf("%v\n", v)
// 	fmt.Printf("%v\n", *v)
// 	v1 := make([]int, 0)
// 	fmt.Printf("%v\n", v1)
// 	v2 := new(int)
// 	fmt.Printf("%v\n", *v2)
// 	fmt.Println("---------end----------")
// }
