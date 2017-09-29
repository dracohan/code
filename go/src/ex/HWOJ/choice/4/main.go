package main

import "fmt"

func main() {
	var i interface{} = 'A'
	j, _ := i.(int)
	fmt.Println(j)

}
