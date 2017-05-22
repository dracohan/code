package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"book/GoDS/stack/linkedliststack"
	"unicode"
)

func main_stack() {
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		line := text.Text()
		s := strings.FieldsFunc(line, unicode.IsSpace)
		calc(s)
	}
}

func calc(str []string) {
	var sum int
	stack := linkedliststack.New()
	for _, s := range str {
		if IsNumber(s) {
			n, _ := strconv.Atoi(s)
			stack.Push(n)
		} else {
			n2, _ := stack.Pop()
			n1, _ := stack.Pop()
			sum = docalc(n1.(int), n2.(int), s)
			stack.Push(sum)
		}
	}
	fmt.Println(sum)
}

func docalc(n1, n2 int, op string) int {
	var res int
	switch op {
	case "+":
		res = n1 + n2
	case "-":
		res = n1 - n2
	case "*":
		res = n1 * n2
	case "/":
		res = n1 / n2
	default:

	}
	return res
}

func IsNumber(s string) bool {
	for _, r := range s {
		if !unicode.IsDigit(r) {
			return false
		}
	}
	return true
}
