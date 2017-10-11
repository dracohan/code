package main

import (
	"fmt"
)

type moew interface {
	Moew()
}

type Cat struct {
}

func (*Cat) Moew() {
	fmt.Println("Cat.Moew")
}

func main() {
	c := &Cat{}
	c.Moew()
}
