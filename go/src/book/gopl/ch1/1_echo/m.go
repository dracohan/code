package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("start...")
	//	fmt.Println(strings.Join(os.Args[1:], "|"))
	for i := 0; i < len(os.Args); i++ {
		fmt.Println(i, ": ", os.Args[i])
	}
	fmt.Println("end...")
}
