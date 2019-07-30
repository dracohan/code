package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// 问题描述：
// 输入一个整数n，求n的二进制表示中，一共有多少个1。例如n=8，二进制表示为00001000，二进制表示中有1个1。

// 分析：
// 如果一个数n不为0，那么n-1的二进制表示，与n的二进制表示相比，n的二进制表示最右边的1变为0，而最右边的1所对应的0全部变为1。其余位不受影响。
// 例如：n的二进制表示为****1000，则n-1的二进制表示为****0111，则n&(n-1)的二进制表示为****0000。将n二进制表示中最右边的1去掉了。
// 将n赋值为n&(n-1)，继续循环此操作，直到n为0。
func count(n int) int {
	var r int
	for n != 0 {
		n = n & (n - 1)
		r++
	}
	return r
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	fmt.Println("Please input the number: ")
	for text.Scan() {
		line := text.Text()
		line = strings.Trim(line, " !~-_")
		num, err := strconv.Atoi(line)
		if err != nil {
			fmt.Println("Wrong input format!")
		} else {
			fmt.Println("The number of 1 is: ", count(num))
		}
		fmt.Println("Please input the number: ")
	}
}
