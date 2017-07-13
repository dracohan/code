package main

import (
	"errors"
	"fmt"
)

func main() {
	fmt.Println("---------------")
	e := errors.New("blabla")
	fmt.Println(e.Error())
	//	recover()
	fmt.Println("---------------")
}
