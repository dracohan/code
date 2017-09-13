package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var values []int
var res []string

func calc(v []int) {
	n := v[0]
	a := v[1:]

	var n1, n2 int
	var b1, b2 int
	var l1, l2 int
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			b1, n1 = a[j], a[j]
			b2, n2 = a[j+1], a[j+1]
			l1 = 1
			l2 = 1
			for n1/10 != 0 {
				l1++
				n1 = n1 / 10
			}
			for n2/10 != 0 {
				l2++
				n2 = n2 / 10
			}
			n1 = b1
			n2 = b2
			if l1 < l2 {
				gap := l2 - l1
				for gap != 0 {
					n1 *= 10
					gap--
				}
			} else {
				gap := l1 - l2
				for gap != 0 {
					n2 *= 10
					gap--
				}
			}
			if n1 < n2 {
				a[j], a[j+1] = a[j+1], a[j]
			}
		}
	}

	var sx string
	for _, x := range a {
		sx += strconv.Itoa(x)
	}

	res = append(res, sx)

	values = make([]int, 0)
}

func main_old() {
	text := bufio.NewScanner(os.Stdin)
	values = make([]int, 0)
	var i int
	for text.Scan() {
		line := text.Text()
		i++
		str := strings.Split(line, " ")
		if len(str) == 1 {
			value, _ := strconv.Atoi(str[0])
			values = append(values, value)
		} else {
			for _, s := range str {
				value, _ := strconv.Atoi(s)
				values = append(values, value)
			}
		}

		if i%2 == 0 {
			calc(values)
		}
	}

	for _, s := range res {
		fmt.Println(s)
	}
}
