package main

import (
	"fmt"

	"book/LearningGo/ch03/even"
)

func main() {
	i := 5
	fmt.Printf("Is %d even? %v\n", i, even.Even(i))
}
