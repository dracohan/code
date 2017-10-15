package main

import (
	"fmt"
)

func gcd(x, y int) int {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

func main() {
	fmt.Printf("gcd of %d and %d is %d: \n", 12, 8, gcd(12, 8))
}
