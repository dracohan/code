package main

import (
	"fmt"
	"sort"
)

func main() {
	person := map[string]int{
		"a": 2,
		"b": 1,
		"c": 4,
		"d": 5,
		"e": 10,
		"f": 4,
	}

	var ages []int

	for _, age := range person {
		ages = append(ages, age)
	}
	sort.Ints(ages)
	fmt.Println(ages)
}
