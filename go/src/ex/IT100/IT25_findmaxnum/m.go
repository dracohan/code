package main

//https://my.oschina.net/jimmyhan/blog/596685
// 问题描述：
// 实现一个函数，求出字符串中的连续最长数字串。例如输入”12345cbf3456″，输出”12345″。

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func findmaxnum(str string) (int, int) {
	var max, start, l int
	rs := []rune(str)
	for i := 0; i < len(str)-1; i++ {
		if unicode.IsDigit(rs[i]) {
			l++
		} else {
			if l > max {
				max = l
				start = i - l
			}
			l = 0
		}

	}
	return start, max
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	for text.Scan() {
		line := text.Text()
		start, length := findmaxnum(line)
		fmt.Println("The max is:", line[start:start+length])
	}
}
