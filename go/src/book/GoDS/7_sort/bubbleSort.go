package main

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
