package main

import (
	"fmt"
)

//Question1: the data structure represent chessboard
type chessboard struct {
	piece [6][7]int
}

//Question2: print the chessboad
//player1(black): chessboard.piece = 1
//player2(white): chessboard.piece = 2
func printc(c chessboard) {
	fmt.Println("The chessboard:")
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

func main() {
	var c chessboard
	for i := 0; i < 6; i++ {
		for j := 0; j < 7; j++ {
			c.piece[i][j] = 0
		}
	}
	printc(c)
	c.piece[0][3] = 1
	c.piece[3][2] = 1
	c.piece[2][3] = 2
	c.piece[3][5] = 2
	printc(c)

}
