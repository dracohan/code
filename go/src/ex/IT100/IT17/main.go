package main

import (
	"bufio"
	"fmt"
	"os"
)

var set map[rune]int

func findChar(s string) rune {
	set = make(map[rune]int)
	rs := []rune(s)
	for _, r := range rs {
		set[r]++
	}
	for r, n := range set {
		if n == 1 {
			return r
		}
	}
	return ' '
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	for text.Scan() {
		line := text.Text()
		r := findChar(line)
		if r != ' ' {
			fmt.Println("The first char is: ", string(r))
		} else {
			fmt.Println("Not exist")
		}
	}
}
