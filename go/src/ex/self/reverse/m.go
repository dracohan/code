package main

import (
	"fmt"
)

func revstr(str string) string {
	var out string
	for _, s := range str {
		out = string(s) + out
	}
	return out
}
func main() {
	s := "abc"
	fmt.Println(revstr(s))
}
