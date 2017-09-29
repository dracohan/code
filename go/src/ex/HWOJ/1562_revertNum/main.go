package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func mylen(n int) int {
	num := 0
	for ; n/10 != 0; n /= 10 {
		num++
	}
	return num + 1
}

func rev(n int) int {
	res := 0
	for ; n/10 != 0; n /= 10 {
		res = res*10 + n%10
	}
	res = res*10 + n
	return res
}

func main() {
	var n int
	text := bufio.NewScanner(os.Stdin)

	for text.Scan() {
		n, _ = strconv.Atoi(text.Text())
		fmt.Println(mylen(n), rev(n))
	}
}
