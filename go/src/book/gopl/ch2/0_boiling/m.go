package main

import (
	"fmt"
)

const boiling = 212.0

func main() {
	var f = boiling
	var c = (f - 32) * 5 / 9
	fmt.Printf("boiling point = %gF or %gC\n", f, c)
}
