package main

import (
	"fmt"
	"os"
	"time"
)

func launch() {
	fmt.Println("Go!")
}

func main() {
	fmt.Println("Commencing countdown.  Press return to abort.")
	tick := time.Tick(1 * time.Second)

	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1)) // read a single byte
		abort <- struct{}{}
	}()

	for countdown := 10; countdown > 0; countdown-- {
		select {
		case <-tick:
			fmt.Println(countdown)
		case <-abort:
			fmt.Println("Launch aborted!")
			return
		}
	}
	launch()
}
