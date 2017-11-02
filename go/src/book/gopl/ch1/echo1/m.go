// Echo1 prints its command-line arguments.
package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	//	var s, sep string
	//	for i := 0; i < len(os.Args); i++ {
	//		s += sep + os.Args[i]
	//		sep = " "
	//	}
	//	fmt.Println(s)
	fmt.Println(os.Args[1:])
	fmt.Println(strings.Join(os.Args[1:], " "))
	var i *int
	var j int
	j = 2
	i = &j
	fmt.Println("id is:", i)
}
