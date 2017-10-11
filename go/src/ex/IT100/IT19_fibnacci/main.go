package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func fib(num int) int {
	if num == 1 || num == 2 {
		return num
	}

	var count int
	var v1, v2, v3 int
	for v1, v2 = 0, 1; count < num-2; count++ {
		v3 = v1 + v2
		v1 = v2
		v2 = v3
	}
	return v3
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	for text.Scan() {
		line := text.Text()
		num, ok := strconv.Atoi(line)
		if ok != nil {
			fmt.Printf("Please input a positive number, current %d\n", num)
		}
		res := fib(num)
		fmt.Printf("fibnacci of %d is %d.", num, res)
	}
}
