package main

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
