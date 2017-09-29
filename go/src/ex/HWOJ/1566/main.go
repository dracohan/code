package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func last(n int) {
	count := 100
	a := make([]int, count)
	for t := 0; t < len(a); t++ {
		a[t] = t + 1
	}

	l := count
	i := 0
	j := 1

	for l >= n {
		if a[i%100] > 0 {
			if j%n == 0 {
				a[i%100] = -1
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

	var res []string
	for i := 0; i < count; i++ {
		if a[i] != -1 {
			res = append(res, strconv.Itoa(a[i]))
		}
	}
	fmt.Println(strings.Join(res, ","))
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	var n int
	for text.Scan() {
		n, _ = strconv.Atoi(text.Text())
		if n <= 1 || n >= 100 {
			fmt.Println("ERROR")
			continue
		}
		last(n)
	}
}
