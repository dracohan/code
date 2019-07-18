package main

import (
	"fmt"
)

func main() {
	fmt.Println("create a map and add/remove elements")
	m := make(map[string]int)
	m["alice"] = 1
	m["ddd"] = 2
	delete(m, "ddd")
	n := map[string]int{
		"aaa":    2,
		"ccc":    1,
		"afds":   3,
		"adf":    4,
		"asdfas": 1,
		"afd":    41,
		"asdf":   123,
		"fdsa":   1,
		"1111":   1,
		"2222":   3,
		"112312": 2132,
	}
	for _, name := range n {
		fmt.Printf("name: %s\n", name)
	}

	_, ok := n["aaa"]
	if ok {
		fmt.Println("ok")
	}

	fmt.Println(m)
}
