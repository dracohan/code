package main

import (
	"fmt"
)

// 给定字符串和左旋的字符数，写程序实现字符串的左旋操作。例如对于字符串”12345678″,
// 左旋转4个字符后，变成”56781234″。要求时间复杂度为O(n)，空间复杂度O(1)。

func rotate(s string, n int) (r string) {
	l := len(s)
	if n <= 0 || n >= l {
		return s
	}
	s1 := s[:n]
	s2 := s[n:]
	r = s2 + s1
	return
}

func main() {
	fmt.Println("output:")
	s := "12345678"
	r := rotate(s, 7)
	fmt.Println(r)
}
