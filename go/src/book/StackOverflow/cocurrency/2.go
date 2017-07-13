package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup // 1

func routine(i int) {
	defer wg.Done() // 3
	fmt.Printf("routine %v finished\n", i)
}

func a() {
	wg.Add(10) // 2
	for i := 0; i < 10; i++ {
		go routine(i) // *
	}
	wg.Wait() // 4
	fmt.Println("main finished")
}
