package main

import (
	"fmt"
)

func fib(n int) []int {
	x, y := 0, 1
	var res []int
	for i := 0; i <= n; i++ {
		x, y = y, x+y
		res = append(res, x)
	}
	return res
}

func main() {
	res := fib(10)
	for _, r := range res {
		fmt.Printf("%d ", r)
	}
}
