package main

import (
	"fmt"
)

func printDigit(i int) {
	fmt.Printf("%d", i)
}

func printOut(n int) {
	if n >= 10 {
		printOut(n / 10)
	}
	printDigit(n % 10)
}

func main() {
	fmt.Println("start...")
	printOut(123)
}
