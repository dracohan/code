package main

import (
	"flag"
	"fmt"
	"regexp"
	"strings"
)

var input string

func main() {
	flag.Parse()
	args := flag.Args()
	if args != nil && len(args) > 0 {
		input = strings.ToLower(args[0])
	}

	fmt.Println(args[0])
	v, err := regexp.Compile(`^[A-Za-z]`)
	fmt.Println(v.FindString(input), err)

}
