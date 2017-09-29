package main

import "fmt"

func f() (result int) {
	t := 5
	defer func() {
		t = t + 5
	}()
	return t
}

//func f() (r int) {
//	defer func(r int) {
//		r = r + 5
//	}(r)
//	return 0
//}

//func f1() (t int) {
//	t = 5
//	defer func() {
//		t = t + 5
//	}()
//	defer func() {
//		t = t * 2
//	}()
//	return t
//}

//const (
//	A = iota
//	B
//	C = "c"
//	D
//	E = iota
//	F
//)

//const (
//	X = 3 * iota
//	Y
//	Z
//)

func main() {
	fmt.Println(f())
	//	fmt.Println(f1())
	//	fmt.Println(B, D, E)
}
