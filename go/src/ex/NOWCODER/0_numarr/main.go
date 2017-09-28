package main

/*
题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
输入描述:
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
输出描述:
每组数据输出一个表示最大的整数。
*/

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

var result []string

func rcalc(s string) {
	ss := strings.Split(s, " ")
	sort.Sort(sort.Reverse(sort.StringSlice(ss)))
	sss := strings.Join(ss, "")
	result = append(result, sss)
}

func main() {
	text := bufio.NewScanner(os.Stdin)

	var i int
	for text.Scan() {
		i++
		line := text.Text()
		if i%2 == 0 {
			rcalc(line)
		}
	}
	for _, x := range result {
		fmt.Println(x)
	}
}
