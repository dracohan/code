package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

var values []int

func calc(v []int) {
	n := v[0]
	a := v[1:]

	var n1, n2 int
	var l1, l2 int
	for i := 0; i < n; i++ {
		for j := 0; j < n-i; j++ {
			n1 = a[j]
			n2 = a[j+1]
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
			if l1 < l2 {
				n1 = n1 * (l2 - l1) * 10
			} else {
				n2 = n2 * (l1 - l2) * 10
			}
			if n1 < n2 {
				a[j], a[j+1] = a[j+1], a[j]
			}
		}
	}

	for _, x := range a {
		print(x)
	}

	values = make([]int, 0)
}

func main() {
	br := bufio.NewReader(os.Stdin)
	values = make([]int, 0)
	var i int
	for {
		line, isPrefix, err := br.ReadLine()
		i++
		if err != nil {
			if err != io.EOF {
				fmt.Println(err.Error())
			}
			break
		}

		if isPrefix {
			fmt.Println("A too long line, seems unexpected")
			return
		}

		str := string(line)
		value, err := strconv.Atoi(str)

		if err != nil {
			fmt.Println(err.Error())
			return
		}

		values = append(values, value)

		if i%2 == 0 {
			calc(values)
		}
	}
}
