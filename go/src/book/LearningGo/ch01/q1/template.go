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
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}

	var j int
label1:
	fmt.Println(j)
	j++
	if j < 10 {
		goto label1
	}

	var arr []int
	arr = []int{4, 3, 2, 1}
	for kk, k := range arr {
		fmt.Printf("arr[%d]:%d\n", kk, k)
	}
	fmt.Println("---------end----------")
}
