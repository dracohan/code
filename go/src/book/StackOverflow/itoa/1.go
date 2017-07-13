package main

import "fmt"

const (
	Low = 5 * iota
	Medium
	High
)

func main() {
	// Use our iota constants.
	fmt.Println(Low)
	fmt.Println(Medium)
	fmt.Println(High)
}
