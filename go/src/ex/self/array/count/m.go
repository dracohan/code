//https://zhuanlan.zhihu.com/p/46730212
// 给你一个有序整数数组，数组中的数可以是正数、负数、零，请实现一个函数，这个函数返回一个整数：返回这个数组所有数的平方值中有多少种不同的取值。举例：

// nums = {-1,1,1,1},
// 那么你应该返回的是：1。因为这个数组所有数的平方取值都是1，只有一种取值
// nums = {-1,0,1,2,3}
// 你应该返回4，因为nums数组所有元素的平方值一共4种取值：1,0,4,9

package main

import (
	"fmt"
)

//version 1
func count1(arr []int) int {
	if len(arr) == 0 {
		return -1
	}
	t := make(map[int]int)
	for _, x := range arr {
		t[x*x]++
	}
	return len(t)
}

//version 2
func count2(arr []int) int {
	if len(arr) == 0 {
		return -1
	}
	var i, j = 0, len(arr) - 1
	var res int
	for i <= j {
		n1 := abs(arr[i])
		n2 := abs(arr[j])
		if n1 > n2 {
			res++
			for i <= j && abs(arr[i]) == n1 {
				i++
			}
		} else if n1 < n2 {
			res++
			for i <= j && abs(arr[j]) == n2 {
				j--
			}
		} else {
			res++
			for i <= j && abs(arr[i]) == n1 {
				i++
			}
			for i <= j && abs(arr[j]) == n2 {
				j--
			}

		}
	}
	return res
}

func abs(i int) int {
	if i > 0 {
		return i
	} else {
		return -i
	}
}

func main() {
	var a []int = []int{-4, -2, -2, -1, 0, 1, 3, 5, 5}
	res := count2(a)
	fmt.Println(res)
}
