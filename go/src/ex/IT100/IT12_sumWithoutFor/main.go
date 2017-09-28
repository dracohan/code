package main

import (
	"fmt"
)

type object struct {
	s int
}

func inttobool(i int) bool {
	if i == 0 {
		return false
	} else {
		return true
	}

}

var s int

func sum(n int) int {
	fmt.Println(n != 0 && inttobool(sum(n-1)))
	s = s + n
	return s
}

func main() {
	fmt.Println("sum calc:", sum(10))
}
