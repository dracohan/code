package main

import (
	"fmt"
)

func main() {
	ch := make(chan int, 1)
	for i := 0; i < 10; i++ {
		select {
		case x := <-ch:
			fmt.Println(x)
		case ch <- i:
		}
	}

	ch1 := make(chan int, 1)

	close(ch1)
	ch1 <- 11
	fmt.Println(<-ch1)

}
