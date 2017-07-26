package main

import (
	"fmt"
	"reflect"
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
	s := S{name: "aa", age: 23}
	var i I
	i = s
	i.boo()
	fmt.Println("---------end----------")
	tag := reflect.ValueOf(s).Field(0).String()
	fmt.Println(tag)
}
