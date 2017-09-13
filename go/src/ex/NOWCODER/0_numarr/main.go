package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

var result []string

func rcalc(s string) {
	ss := strings.Split(s, " ")
	sort.Sort(sort.Reverse(sort.StringSlice(ss)))
	sss := strings.Join(ss, "")
	result = append(result, sss)
}

func main() {
	text := bufio.NewScanner(os.Stdin)

	var i int
	for text.Scan() {
		i++
		line := text.Text()
		if i%2 == 0 {
			rcalc(line)
		}
	}
	for _, x := range result {
		fmt.Println(x)
	}
}
