package main

import (
	stack "book/GoDS/stack/arraystack"
	"fmt"
)

type MinStack struct {
	stacks *stack.Stack
	mins   *stack.Stack
}

func (ms *MinStack) Push(value int) {
	ms.stacks.Push(value)

	if ms.mins.Empty() {
		ms.mins.Push(value)
	} else {
		x, ok := ms.mins.Peek()
		if !ok {
			return
		}

		if value <= x.(int) {
			ms.mins.Push(value)
		}
	}

}

func (ms *MinStack) Pop() {
	x := ms.Top()
	ms.stacks.Pop()

	v, ok := ms.mins.Peek()
	if !ok {
		return
	}

	if x == v {
		ms.mins.Pop()
	}
}

func (ms *MinStack) Top() int {
	r, ok := ms.stacks.Peek()
	if !ok {
		return -1
	}
	return r.(int)
}

func (ms *MinStack) GetMin() int {
	r, ok := ms.mins.Peek()
	if !ok {
		return -1
	}
	return r.(int)
}

func main() {
	a := []int{6, 7, 5, 9, 3, 3, 4}
	s := &MinStack{stacks: stack.New(), mins: stack.New()}
	for _, i := range a {
		s.Push(i)
	}
	fmt.Println(s.GetMin())
	for i := 0; i < 4; i++ {
		s.Pop()
	}
	fmt.Println(s.GetMin())
}
