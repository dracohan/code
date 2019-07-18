package main

import (
	"fmt"
)

func revstr(str string) string {
	var out string
	for _, s := range str {
		out = string(s) + out
	}
	return out
}

func revint(n int) int {
	var out int
	for ; n/10 != 0; n = n / 10 {
		out = out*10 + n%10
	}
	out = out*10 + n
	return out
}

func revarr(a []int) []int {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	s := "abc"
	fmt.Println(revstr(s))

	i := 1234
	fmt.Println(revint(i))

	arr := []int{1, 2, 3, 4, 5, 6, 7}
	fmt.Println(revarr(arr))
}
