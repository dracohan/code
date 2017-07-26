package main

import (
	"fmt"
	"log"
	"os/exec"
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
	cmd := exec.Command("echo", "aa")
	err := cmd.Start()
	if err != nil {
		log.Fatal(err)
	}
	err = cmd.Wait()
	fmt.Println("---------end----------")
}
