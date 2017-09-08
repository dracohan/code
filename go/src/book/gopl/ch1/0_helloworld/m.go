package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("helloworld")
	os.Create("abc")
}
