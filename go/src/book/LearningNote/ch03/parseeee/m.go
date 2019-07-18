package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println("start")
	n, err := strconv.ParseInt("13", 16, 32)
	if err != nil {
		fmt.Println("err")
	}
	fmt.Println(n)
}
