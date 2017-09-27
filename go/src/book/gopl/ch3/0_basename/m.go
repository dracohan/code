package main

import (
	"fmt"
	"strings"
)

func basename(s string) string {
	if slash := strings.LastIndex(s, "/"); slash != -1 {
		s = s[slash+1:]
	}
	if dot := strings.LastIndex(s, "."); dot > 0 {
		s = s[:dot]
	}
	return s
}

func main() {
	s := "a/b/c.d.go"
	ss := s[:]
	fmt.Println(len(ss), " ", cap(ss))
	fmt.Println(ss)
	fmt.Printf("basename of %s is %s\n", s, basename(s))
}
