package main

import (
	"fmt"
	"io/ioutil"
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

	as := "another string.."
	ioutil.WriteFile("test1.txt", []byte(as), 644)
	files, _ := ioutil.ReadDir(".")
	for _, f := range files {
		fmt.Println(f.Name())
	}
	fmt.Println("---------end----------")
}
