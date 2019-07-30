package main

// 问题描述：

// 一个台阶总共有n阶，一次可以跳1级或者2级。求总共有多少种跳法。
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func step(n int) int {
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	return step(n-1) + step(n-2)
}

func main() {
	text := bufio.NewScanner(os.Stdin)
	fmt.Println("Please input the step num:")
	for text.Scan() {
		line := text.Text()
		line = strings.Trim(line, " ")
		num, err := strconv.Atoi(line)
		if err != nil {
			fmt.Printf("Wrong input format!\n\n")
		} else {
			fmt.Printf("The method account is: %d\n\n", step(num))
		}
		fmt.Println("Please input the step num:")
	}
}
