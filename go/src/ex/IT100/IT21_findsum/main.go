package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var aux []int

func printa(aux []int, n int) {
	for n, a := range aux {
		if a != 0 {
			fmt.Printf("%d ", n)
		}
	}
	fmt.Println()
}

func helper(m, cur, n int) {
	if m == 0 {
		fmt.Println("Got one: ")
		printa(aux, n)
		return
	}
	if m < 0 || cur > n {
		return
	}
	helper(m, cur+1, n)

	aux[cur] = 1
	helper(m-cur, cur+1, n)
	aux[cur] = 0
}

func findCombi(n, m int) {
	aux = make([]int, n+1)
	if n > m {
		findCombi(m, m)
	} else {
		helper(m, 1, n)
	}
}

func main() {
	var n, m int
	text := bufio.NewScanner(os.Stdin)
	for text.Scan() {
		line := text.Text()
		nums := strings.Split(line, " ")
		if len(nums) != 2 {
			fmt.Println("Please input two numbers")
		} else {
			n, _ = strconv.Atoi(nums[0])
			m, _ = strconv.Atoi(nums[1])
			findCombi(n, m)
		}
	}
}
