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

var root *node

func add(pi, in int) {
	if pi == 0 {
		if root == nil {
			root = &node{nil, 0, 0}
		}
		node := &node{root, in, 1}
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
			nodes = make(map[int]*node, num)
			first = false
		} else {
			r := strings.Split(line, " ")
			pi, _ := strconv.Atoi(r[0])
			in, _ := strconv.Atoi(r[1])
			add(pi, in)
		}
	}

	var max int
	for _, n := range nodes {
		height := n.height
		if height > max {
			max = height
		}
	}
	fmt.Println(max)
}
