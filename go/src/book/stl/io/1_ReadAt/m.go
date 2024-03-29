package main

import (
	"fmt"
	"strings"
)

func main() {
	reader := strings.NewReader("Goabcdefghijk")
	p := make([]byte, 6)
	n, err := reader.ReadAt(p, 2)
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s, %d\n", p, n)
}
