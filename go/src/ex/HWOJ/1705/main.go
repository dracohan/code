package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func calMax(str []string) {
	var arr []int
	for _, s := range str {
		n, _ := strconv.Atoi(s)
		arr = append(arr, n)
	}
	
	for i := len(arr) -1; i >=0; i-- {
		n = getMax(arr, i)
		if isLarger(arr[i-1], )
	}
}

func getMax(v []int, n int) int {
	if n == len(v) - 1{
		return 1
	}
	if isLarger(v[n], v[n+1:]) {
		max = v[n]
		num++
	} else {
		getMax(v, n--)
	}
}

func main() {
	scn := bufio.NewScanner(os.Stdin)
	for scn.Scan() {
		line := scn.Text()
		str := strings.Split(line, " ")

		calMax(str)

	}
}
