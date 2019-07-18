package main

import (
	"fmt"
)

func main() {
	b := []int{
		1, 2, 3, 5,
		123333123,
	}

	fmt.Println(&b)

	var s string = "adfb"
	fmt.Println(&s)
	fmt.Println(s[1:])
	r := rune(s)
	fmt.Println(r)
}
