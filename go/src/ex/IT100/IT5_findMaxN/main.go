package main

import (
	"fmt"
)

//每次选出一个最大值，放在数组的最后
func bubbleSort(a []int) {
	var done bool
	//设定比较的范围从0 to end，每一个元素都要来一遍
	for i := 0; i < len(a) && done != true; i++ {
		done = true
		//遍历比较的范围，将最大值移动到最后一个元素
		for j := 0; j < len(a)-1-i; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				done = false
			}
		}
	}
}

func findMax(a []int, n int) []int {
	r := make([]int, n)
	l := len(a)
	bubbleSort(a)
	for i := 0; i < n; i++ {
		r[n-1-i] = a[l-1-i]
	}
	return r

}

func main() {
	a := []int{14, 5, 16, 3, 11, 10, 15, 30}
	res := findMax(a, 3)
	for _, n := range res {
		fmt.Printf("%d, ", n)
	}
}
