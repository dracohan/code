package main

import (
	"fmt"
	"strconv"
	"strings"
)

func trimnum(s string) string {
	var ns string
	r := []rune(s)
	for i := 0; i < len(r); i++ {
		if (r[i] >= 'a' && r[i] <= 'z') || (r[i] >= 'A' && r[i] <= 'Z') {
			ns += string(r[i])
		}
	}
	return ns
}
func main() {
	str := "ABC19dAd8A"
	fmt.Println(strings.ToLower(trimnum(str)))
}
