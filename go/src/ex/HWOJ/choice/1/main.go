package main

import "fmt"

func fun(n int) int {
	var s int
	if n == 1 || n == 2 {
		s = 3
	} else {
		s = n - fun(n-1)
	}
	return s
}

func main() {
	fmt.Println(fun(3))
}
