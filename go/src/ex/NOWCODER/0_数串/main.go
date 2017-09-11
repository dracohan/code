package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func main() {
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		nr := text.Text()
		sr := text.Text()
		n := strings.FieldsFunc(nr, unicode.IsSpace)
		s := strings.FieldsFunc(sr, unicode.IsSpace)
		fmt.Printf("%s: %s", n, s)
	}
}
