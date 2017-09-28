package main

//把数组拆分成小的块，然后再合并
func mergesort(a []int) {
	res := make([]int, len(a))
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
	num := rightEnd - leftPos + 1

	for ; leftPos <= leftEnd && rightPos <= rightEnd; tmpPos++ {
		if a[leftPos] < a[rightPos] {
			res[tmpPos] = a[leftPos]
			leftPos++
		} else {
			res[tmpPos] = a[rightPos]
			rightPos++
		}
	}

	for ; leftPos <= leftEnd; tmpPos, leftPos = tmpPos+1, leftPos+1 {
		res[tmpPos] = a[leftPos]
	}

	for ; rightPos <= rightEnd; tmpPos, rightPos = tmpPos+1, rightPos+1 {
		res[tmpPos] = a[rightPos]
	}

	//只拷贝rightEnd结尾的num个元素
	for i := 0; i < num; i, rightEnd = i+1, rightEnd-1 {
		a[rightEnd] = res[rightEnd]
	}
}
