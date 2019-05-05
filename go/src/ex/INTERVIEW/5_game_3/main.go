package main

import (
	"fmt"
	"math/rand"
	"time"
)

type chessboard struct {
	piece    [6][7]int
	inserted int
	over     int
}

func (c *chessboard) printc(str string) {
	fmt.Println("The", str, "chessboard:")
	for i := 0; i < 6; i++ {
		for j := 0; j < 7; j++ {
			if c.piece[i][j] == 0 {
				fmt.Print(".")
			} else if c.piece[i][j] == 1 {
				fmt.Print("X")
			} else if c.piece[i][j] == 2 {
				fmt.Print("O")
			} else {
				fmt.Println("You should never get here")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func (c *chessboard) play() {
	var player = 0
	for c.over != 1 {
		rand.Seed(time.Now().UnixNano())
		cl := rand.Intn(7)
		c.insert(cl, player)
		c.printc("interim")
		player = (player + 1) % 2
	}
}

func (c *chessboard) insert(cl int, player int) {
	for i := 6; i > 0; i-- {
		if c.piece[i-1][cl] == 0 {
			c.inserted += 1
			if player == 0 {
				c.piece[i-1][cl] = 1
				//check everytime when insert
				c.check(i-1, cl, 1)
				return
			} else if player == 1 {
				c.piece[i-1][cl] = 2
				//check everytime when insert
				c.check(i-1, cl, 2)
				return
			}
		}
	}
}

//check all the 4 directions for the position i, j of player p
func (c *chessboard) check(i int, j int, p int) {
	var count int
	//check leftward
	for n := 1; j-n >= 0 && c.piece[i][j-n] == p; n++ {
		count++
	}
	//check rightward
	for n := 1; j+n <= 6 && c.piece[i][j+n] == p; n++ {
		count++
	}
	if count >= 3 {
		c.over = 1
		return
	}

	count = 0
	//check upward
	for n := 1; i-n >= 0 && c.piece[i-n][j] == p; n++ {
		count++
	}
	//check downward
	for n := 1; i+n <= 5 && c.piece[i+n][j] == p; n++ {
		count++
	}
	if count >= 3 {
		c.over = 1
		return
	}

	count = 0
	//check leftupward
	for n := 1; i-n >= 0 && j-n >= 0 && c.piece[i-n][j-n] == p; n++ {
		count++
	}
	//check rightdownward
	for n := 1; i+n <= 5 && j+n <= 6 && c.piece[i+n][j+n] == p; n++ {
		count++
	}
	if count >= 3 {
		c.over = 1
		return
	}

	count = 0
	//check leftdownward
	for n := 1; i+n <= 5 && j-n >= 0 && c.piece[i+n][j-n] == p; n++ {
		count++
	}
	//check rightupward
	for n := 1; i-n >= 0 && j+n <= 6 && c.piece[i-n][j+n] == p; n++ {
		count++
	}
	if count >= 3 {
		c.over = 1
		return
	}

	if c.inserted == 42 {
		fmt.Println("Equal")
		c.over = 1
		return
	}
}

func main() {
	var c chessboard
	for i := 0; i < 6; i++ {
		for j := 0; j < 7; j++ {
			c.piece[i][j] = 0
		}
	}
	c.printc("original")
	c.play()
	c.printc("final")
}
