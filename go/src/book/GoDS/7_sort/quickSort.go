package main

func quickSort(values []int, left, right int) {
	temp := values[left]
	p := left
	i, j := left, right

	for i <= j {
		//找到第一个比temp小的数
		for j >= p && values[j] >= temp {
			j--
		}
		//将该数值赋值给p
		if j >= p {
			values[p] = values[j]
			p = j
		}
		//找到第一个比temp大的数
		if values[i] <= temp && i <= p {
			i++
		}
		//将该数值赋值给p
		if i <= p {
			values[p] = values[i]
			p = i
		}
	}
	values[p] = temp
	if p-left > 1 {
		quickSort(values, left, p-1)
	}
	if right-p > 1 {
		quickSort(values, p+1, right)
	}

}

func QuickSort(values []int) {
	quickSort(values, 0, len(values)-1)
}
