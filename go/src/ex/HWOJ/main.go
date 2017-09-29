package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func last(n int) {
	a := make([]int, n)
	for t := 0; t < len(a); t++ {
		a[t] = t + 1
	}

	l := n
	i := 0
	j := 1

	for l > 1 {
		if a[i%n] > 0 {
			if j%3 == 0 {
				a[i%n] = -1
				l--
				i++
				j = 1
			} else {
				i++
				j++
			}
		} else {
			i++ //-1
		}
	}

	for i := 0; i < n; i++ {
		if a[i] != -1 {
			fmt.Println(a[i])
		}
	}
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	var n int
	for text.Scan() {
		n, _ = strconv.Atoi(text.Text())
		last(n)
	}
}
