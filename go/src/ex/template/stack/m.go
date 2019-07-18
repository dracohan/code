package main

import (
	"fmt"
)

type stack struct {
	sl []int
}

func (s *stack) push(i int) {
	s.sl = append(s.sl, i)
}

func (s *stack) pop() int {
	r := s.sl[len(s.sl)-1]
	s.sl = s.sl[:len(s.sl)-1]
	return r
}

func main() {
	fmt.Println("simulate stack with slice")
	s := &stack{}
	for i := 0; i < 10; i++ {
		s.push(i)
	}
	fmt.Println(s.sl)

}
