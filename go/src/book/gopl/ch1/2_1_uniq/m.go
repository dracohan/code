package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	fmt.Println("start")
	lines := make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		lines[input.Text()]++
	}
	for line, n := range lines {
		fmt.Println(n, ": ", line)
	}
	fmt.Println("end")
}
