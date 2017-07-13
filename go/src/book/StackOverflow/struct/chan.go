package main

import (
	"fmt"
	"time"
)

func main() {
	done := make(chan struct{})
	go func() {
		time.Sleep(1 * time.Second)
		close(done)
	}()

	fmt.Println("Wait...")
	<-done
	fmt.Println("done.")
}
