package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func last(m, n int) int {
	count := m
	a := make([]int, count)
	for t := 0; t < len(a); t++ {
		a[t] = t + 1
	}

	l := count //length
	i := 0     //index
	j := 1     //counting

	for l > 1 {
		if a[i%m] > 0 { //not deselected yet
			if j%n == 0 {
				a[i%m] = -1
				l--
				i++
				j = 1
			} else {
				i++
				j++
			}
		} else {
			i++ //deselected already
		}
	}
	for i := 0; i < count; i++ {
		if a[i] != -1 {
			return i
		}
	}

	return -1
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	text.Scan()
	m, _ := strconv.Atoi(text.Text())
	text.Scan()
	n, _ := strconv.Atoi(text.Text())
	r := last(m, n)
	fmt.Println("last number is: ", r)

}
