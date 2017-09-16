package main

import (
	"bufio"
	"fmt"
	"os"
)

var nr []rune
var sec []rune

func reverse(r []rune) []rune {
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return r
}

func reverseStr(s string) {
	r := []rune(s)
	var start, end int
	for i := 0; i < len(r); i++ {
		if r[end] == ' ' || end == len(r)-1 {
			if start == end {
				sec = reverse(r[start:])
			} else {
				sec = reverse(r[start:end])
				sec = append(sec, ' ')
			}
			nr = append(nr, sec...)
			start = end + 1
			end++
		} else {
			end++
		}
	}
	reverse(nr)
}

func main() {
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		line := text.Text()
		fmt.Println("Input text: ", line)
		reverseStr(line)
		fmt.Println("Reverse text: ", string(nr))
	}
}
