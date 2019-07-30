package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Create("writeAt.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	file.WriteString("01234567890123456789012345678901234567890")
	n, err := file.WriteAt([]byte("Go语言中文网"), 1)
	if err != nil {
		panic(err)
	}
	fmt.Println(n)
}
