package main

import (
	"fmt"
)

func throwsPanic(f func()) (b bool) {
	defer func() {
		if x := recover(); x != nil {
			b = true
		}
	}()
	f()

	return
}
func foo() {
	fmt.Println("aa")
}

func main() {
	throwsPanic(foo)
}
