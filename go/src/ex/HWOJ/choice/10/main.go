package main

import "fmt"

func modify(array [5]int) {
	array[0] = 10
	fmt.Println(array)
}

func main() {
	array := [5]int{1, 2, 3, 4, 5}
	modify(array)
	fmt.Println(array)

	var a = [2][]int{{1, 0, 1}, {5, 2, 3}}
	var b = [][3]int{{1, 2, 3}, {4, 5, 6}}
	//	var c = [2][4]int{{1, 2, 3}, {4, 5}, {6}}
	var d = [][3]int{{1, 0, 1}, {}, {1, 1}}
	fmt.Println(a, b, d)
}
