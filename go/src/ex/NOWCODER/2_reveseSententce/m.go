package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

var ns []string

func reverseSentence(sarr []string) string {
	ns = make([]string, len(sarr))
	for i := len(sarr) - 1; i >= 0; i-- {
		ns = append(ns, sarr[i])
	}

	return strings.Trim(strings.Join(ns, " "), " ")
}

func main() {
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		line := text.Text()
		trimline := strings.FieldsFunc(line, unicode.IsSpace)
		nline := reverseSentence(trimline)
		fmt.Println(nline)
	}
}
