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

func add(pidx, idx int) {
	if pidx == 0 {
		if root == nil {
			root = &node{nil, 0, 1}
		}
		nodes[idx] = &node{root, idx, 2}
		return
	}

	if pn, ok := nodes[pidx]; ok {
		node := &node{pn, idx, pn.height + 1}
		nodes[idx] = node
	} else {
		fmt.Println("parent not found")
	}
}

var num int
var nodes map[int]*node

func main() {
	text := bufio.NewScanner(os.Stdin)
	first := true
	for text.Scan() {
		line := text.Text()
		if first {
			if num, ok := strconv.Atoi(line); ok == nil {
				nodes = make(map[int]*node, num)
				first = false
			} else {
				fmt.Println("wrong input")
			}
		} else {
			rec := strings.Split(line, " ")
			pidx, _ := strconv.Atoi(rec[0])
			idx, _ := strconv.Atoi(rec[1])
			add(pidx, idx)
		}
	}

	var max int
	for _, n := range nodes {
		if n.height > max {
			max = n.height
		}
	}
	fmt.Println(max)
}
