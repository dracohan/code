package main

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
