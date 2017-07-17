package main

import (
	"fmt"
	"os"
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

	var str []byte = []byte("hello world")
	var f *os.File
	f, _ = os.Create("test.txt")
	f.Write(str)
	//	err := ioutil.WriteFile("test.txt", str, 0644)
	f.Close()
	fmt.Println("---------end----------")
}
