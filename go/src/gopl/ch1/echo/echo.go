package main

import "fmt"
import "os"

func main() {
	ss := ""
	//	fmt.Printf("%s", os.Args[1:])
	for _, s := range os.Args {
		ss += s + " "
	}
	fmt.Println(ss)
}
