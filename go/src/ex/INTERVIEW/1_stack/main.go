package main

import (
	"fmt"
)

type stack struct {
	count int
	array []int
}

func (s *stack) push(i int) {
	s.array = append(s.array, i)
	s.count++
}

func (s *stack) pop() int {
	tmp := s.array[s.count-1]
	s.count--
	return tmp
}

func (s *stack) display() {
	for i := 0; i < s.count; i++ {
		fmt.Println(s.array[i])
	}
}

func main() {
	var s stack
	t := []int{2, 4, 3}

	for _, n := range t {
		s.push(n)
	}
	s.pop()
	//	s.pop()
	s.pop()
	s.display()
}
