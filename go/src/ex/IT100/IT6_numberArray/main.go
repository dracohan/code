package main

import "fmt"

var a, b []int
var success bool

func getB() []int {
	for success != true {
		setNextB()
	}
	return b
}

func setNextB() {
	flag := true
	for i := 0; i < 10; i++ {
		f := getFrequency(i)
		if b[i] != f {
			b[i] = f
			flag = false
		}
	}
	success = flag
}

func getFrequency(value int) int {
	var count int
	for i := 0; i < 10; i++ {
		if b[i] == value {
			count++
		}
	}
	return count
}

func main() {
	a = make([]int, 10)
	b = make([]int, 10)
	for i := 0; i < 10; i++ {
		a[i] = i
		b[i] = i
	}
	b = getB()
	for _, n := range b {
		fmt.Printf("%d ", n)
	}
}
