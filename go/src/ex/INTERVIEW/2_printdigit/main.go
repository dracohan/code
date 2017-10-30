package main

import (
	"fmt"
)

func printDigit(i int) {
	print(i)
}

func printOut(n int) {
	if n < 0 {
		print("-")
		n = -n
	}
	if n >= 10 {
		printOut(n / 10)
	}
	printDigit(n % 10)
}

func main() {
	fmt.Println("start...")
	printOut(-123)
}
