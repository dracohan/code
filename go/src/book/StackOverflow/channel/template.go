package main

import (
	"fmt"
	"time"
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

	msg := make(chan string, 1)
	msg <- "Hey There!"
	go func() {
		fmt.Println(<-msg)
	}()
	time.Sleep(time.Second * 1)
	fmt.Println("---------end----------")
}
