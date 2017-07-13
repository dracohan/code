package main

import (
	"fmt"
	"sync"
	"time"
)

// The pinger prints a ping and waits for a pong
func pinger(pinger <-chan int, ponger chan<- int) {
	for {
		<-pinger
		wg2.Done()
		fmt.Println("ping")
		time.Sleep(time.Second)
		ponger <- 1
	}
}

// The ponger prints a pong and waits for a ping
func ponger(pinger chan<- int, ponger <-chan int) {
	for {
		<-ponger
		wg2.Done()
		fmt.Println("pong")
		time.Sleep(time.Second)
		pinger <- 1
	}
}

var wg2 sync.WaitGroup

func main() {
	wg2.Add(10)
	ping := make(chan int)
	pong := make(chan int)

	go pinger(ping, pong)
	go ponger(ping, pong)

	// The main goroutine starts the ping/ping by sending into the ping channel
	ping <- 1
	wg2.Wait()
	//	for {
	//		// Block the main thread until an interrupt
	//		time.Sleep(time.Second)
	//	}
}
