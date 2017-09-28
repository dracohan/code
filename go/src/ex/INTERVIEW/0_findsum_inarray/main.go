package main

/*
在一个数组中打印所有和为某个值的数字的组合
*/

import (
	"fmt"
)

//从第二个元素开始向后，每次把元素放在正确的位置
func insertionSort(a []int) {
	var i, j int
	//设定遍历范围为2 to end
	for i = 1; i < len(a); i++ {
		x := a[i]
		//如果左边元素大于要比较的值，将其右移
		for j = i; j > 0 && a[j-1] > x; j-- {
			a[j] = a[j-1]
		}
		//正确的位置
		a[j] = x
	}
}

var a []int
var x [100]bool
var sum int
var t int

func findSum(a []int) {
	insertionSort(a)
	backtrace(0)
}

func backtrace(n int) {
	if sum > t {
		print("sum overflow, return\n")
		return
	}
	if sum == t {
		print("sum match, print\n")
		for i, b := range x {
			if b {
				fmt.Printf("%d ", a[i])
			}
		}
		fmt.Println("\n")
	}

	for i := n; i < len(a); i++ {
		print("select: ", i+1, "\n")
		sum += a[i]
		print("sum is: ", sum, "\n")
		x[i] = true
		backtrace(i + 1)
		print("deselect: ", i+1, "\n")
		sum -= a[i]
		print("sum is: ", sum, "\n")
		x[i] = false
	}
}

func main() {
	a = []int{1, 3, 2, 4, 5}
	t = 6
	findSum(a)
}
