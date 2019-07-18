package main

import (
	"fmt"
)

func f() {
	fmt.Println("f() invoked")
}

func hello(f func()) {
	f()
}

func main() {
	fmt.Println("create a function and pass it as argument")
	hello(f)
}
