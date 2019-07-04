package main

import (
	"fmt"
)

func main() {
	i := 1
	j := i
	fmt.Println("addr:", &i)
	fmt.Println("addr:", &j)
}
