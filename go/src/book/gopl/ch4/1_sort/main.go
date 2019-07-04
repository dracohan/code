package main

import (
	"fmt"
	"os"
	"runtime/pprof"
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

	for p, age := range person {
		ages = append(ages, age)
		if age == 4 {
			delete(person, p)
		}
	}
	f, err := os.OpenFile("cpu.prof", os.O_RDWR|os.O_CREATE, 0644)
	if err != nil {
		fmt.Println("Fail to create file!")
	}
	defer f.Close()

	pprof.StartCPUProfile(f)
	fmt.Println(ages)
	sort.Ints(ages)
	if _, ok := person["g"]; !ok {
		person["g"] = 11
		person["g"] = 11
	}
	fmt.Println(person)
	fmt.Println(ages)
	defer pprof.StopCPUProfile()
}
