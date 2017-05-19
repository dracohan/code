package main

import (
	"fmt"
)

func main() {
	add := Operation{Addition{}}
	fmt.Println(add.Operate(3, 5)) // 8

	mult := Operation{Multiplication{}}
	fmt.Println(mult.Operate(3, 5)) // 15
}
