package main

import (
	"fmt"
)

func gcd(m, n int) int {
	for n != 0 {
		rem := m % n
		m = n
		n = rem
	}
	return m
}

func main() {
	n := gcd(48, 16)
	fmt.Println(n)
}
