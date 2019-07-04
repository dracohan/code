package main

import (
	"fmt"
)

func main() {
	fmt.Println("go")
	var s string
	s = "///adfadf"
	s += ", alright"
	fmt.Println(s[3:])
}
