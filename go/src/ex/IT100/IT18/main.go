package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type node struct {
	n *node
	d int
}

func add(h *node, i int) {
	p := &node{h, i}
	h = p
}

func josephus(n, m int) int {
	if m < 1 || n < 1 {
		return -1
	}
	var res int
	for i := 2; i <= n; i++ {
		res = (res + m) % i
	}
	return res
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	text.Scan()
	total, _ := strconv.Atoi(text.Text())
	text.Scan()
	count, _ := strconv.Atoi(text.Text())

	fmt.Println(josephus(total, count))

}
