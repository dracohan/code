package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var r = []int{1, 2, 5, 10, 20, 100}
var sum int

func f(v, l, iStart int) {
	if v < 0 || l >= 100 {
		return
	} else if v == 0 && l < 100 {
		sum++
	} else {
		for i := iStart; i < len(r); i++ {
			f(v-r[i], l+1, i)
		}
	}
}

func main() {
	var n int
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		n, _ = strconv.Atoi(text.Text())
		if n == 0 {
			break
		}
		sum = 0
		f(n, 0, 0)
		fmt.Println(sum)
	}
}
