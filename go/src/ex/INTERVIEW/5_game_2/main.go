package main

import (
	"fmt"
	"math/rand"
	"time"
)

type chessboard struct {
	piece    [6][7]int
	inserted int
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

//The game start
func (c *chessboard) play() {
	var player = 0
	for c.inserted != 42 {
		rand.Seed(time.Now().UnixNano())
		cl := rand.Intn(7)
		c.insert(cl, player)
		player = (player + 1) % 2
	}
}

//Insert player's piece to the bottom of the column
func (c *chessboard) insert(cl int, player int) {
	for i := 6; i > 0; i-- {
		if c.piece[i-1][cl] == 0 {
			c.inserted += 1
			if player == 0 {
				c.piece[i-1][cl] = 1
				return
			} else if player == 1 {
				c.piece[i-1][cl] = 2
				return
			}
		}
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
