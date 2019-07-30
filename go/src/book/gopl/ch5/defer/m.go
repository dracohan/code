package main

import (
	"fmt"
)

func f(n int) {
	fmt.Println(n)
}

func main() {
	defer f(1)
	defer f(2)
	defer f(3)
	defer f(4)
}
