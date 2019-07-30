package main

import (
	"fmt"
)

func f() {
	panic("ohpss")

}

func main() {
	fmt.Println("ready")
	defer func() {
		if p := recover(); p == nil {
			fmt.Errorf("internal error: %v", p)
		}
	}()
	f()
}
