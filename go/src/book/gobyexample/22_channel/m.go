package main

import (
	"fmt"
)

func main() {
	messages := make(chan string)
	go func() { messages <- "ping" }()
	//	go func() { messages <- "ping" }()
	msg := <-messages
	//	msg = <-messages
	fmt.Println(msg)
}
