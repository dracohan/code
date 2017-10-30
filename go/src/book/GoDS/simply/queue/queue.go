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

func (s *stack) peek() int {
	if s.count > 0 {
		tmp := s.array[0]
		s.array = s.array[1:]
		s.count--
		return tmp
	} else {
		return -1
	}
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
	fmt.Println(s.peek())
	//	s.pop()
	//	s.pop()
	s.display()
}
