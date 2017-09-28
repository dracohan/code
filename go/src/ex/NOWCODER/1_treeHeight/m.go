package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
	parent *node
	index  int
	height int
}

func add(pi, in int) {
	if in == 0 {
		root := &node{nil, 0, 0}
		node := &node{root, 0, 1}
		nodes[in] = node
		return
	}

	if pn, ok := nodes[pi]; ok {
		node := &node{pn, in, pn.height + 1}
		nodes[in] = node
	} else {
		fmt.Println("parent not found")
	}
}

var ar []string
var num int
var nodes map[int]*node

func main() {
	text := bufio.NewScanner(os.Stdin)
	first := true
	for text.Scan() {
		line := text.Text()
		if first {
			num, _ = strconv.Atoi(line)
			first = false
		} else {
			r := strings.Split(line, " ")
			pi, _ := strconv.Atoi(r[0])
			in, _ := strconv.Atoi(r[1])
			add(pi, in)
		}
	}

}
