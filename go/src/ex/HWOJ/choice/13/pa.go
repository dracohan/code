package main

import "fmt"

func HavePanic1() (b bool) {
	defer func() {
		if x := recover(); x != nil {
			b = true
		}
	}()
	panic(1)
	return
}

func HavePanic2() (b bool) {
	panic(1)
	if x := recover(); x != nil {
		b = true
	}
	return
}

func main() {
	fmt.Println(HavePanic1())
	fmt.Println(HavePanic2())
}
