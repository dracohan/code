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

//以gap为间隔比较所有的元素
func shellsort(a []int) {
	var j int
	//gap逐渐递减
	for gap := len(a) / 2; gap > 0; gap /= 2 {
		//从gap开始比较每一个元素
		for i := gap; i < len(a); i++ {
			x := a[i]
			//找到以gap为间隔的正确位置
			for j = i; j >= gap && x < a[j-gap]; j -= gap {
				a[j] = a[j-gap]
			}
			a[j] = x
		}
	}
}

//把数组拆分成小的块，然后再合并
func mergesort(a []int) {
	var res []int
	mergesorta(a, res, 0, len(a)-1)
}

func mergesorta(a []int, res []int, l int, r int) {
	if l < r {
		center := (l + r) / 2
		mergesorta(a, res, l, center)
		mergesorta(a, res, center+1, r)
		merge(a, res, l, center+1, r)
	}
}

func merge(a []int, res []int, leftPos int, rightPos int, rightEnd int) {
	leftEnd := rightPos - 1
	tmpPos := leftPos
	numElements := rightEnd - leftPos + 1

	for leftPos <= leftEnd && rightPos <= rightEnd {
		if a[leftPos] < a[rightPos] {
			res[tmpPos] = a[leftPos]
		} else {
			res[tmpPos] = a[rightPos]
		}
		tmpPos++
		leftPos++
	}
	for leftPos <= leftEnd {
		res[tmpPos] = a[leftPos]
		tmpPos++
		leftPos++
	}
	for rightPos <= rightEnd {
		res[tmpPos] = a[rightPos]
		tmpPos++
		rightPos++
	}
	for i := 0; i < numElements; i++ {
		a[rightEnd] = res[rightEnd]
		rightEnd--
	}

}

func main() {
	sep := ","
	t := []int{9, 3, 4, 5, 1, 6, 8, 2, 12, 14, 22, 18, 3, 11}
	//	t := []int{9, 1, 2, 3, 4, 5, 6, 7, 8}
	//	bubbleSort(t)
	//	insertionSort(t)
	//	shellsort(t)
	mergesort(t)
	for i, n := range t {
		if i == len(t)-1 {
			sep = ""
		}
		fmt.Printf("%d%s ", n, sep)
	}
}
