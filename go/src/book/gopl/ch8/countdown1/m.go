package main

import (
	"fmt"
	"time"
)

func launch() {
	fmt.Println("Go!")
}

func main() {
	fmt.Println("Commencing countdown.")
	tick := time.Tick(1 * time.Second)
	for countdown := 10; countdown > 0; countdown-- {
		fmt.Println(countdown)
		t := <-tick
		fmt.Println(t)
	}
	launch()
}
