package main

import (
	"book/GoDS/3_stack/arraystack"
	"fmt"
)

type MinStack struct {
	stacks *arraystack.Stack
	mins   *arraystack.Stack
}

func New() *MinStack {
	return &MinStack{stacks: arraystack.New(), mins: arraystack.New()}
}

func (ms *MinStack) Push(value int) {
	ms.stacks.Push(value)

	if ms.mins.Empty() {
		ms.mins.Push(value)
	}

	x, ok := ms.mins.Peek()
	if !ok {
		return
	}

	if value <= x.(int) {
		ms.mins.Push(value)
	}
}

func (ms *MinStack) Pop() {
	ms.stacks.Pop()

	x := ms.Top()

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
	s := New()
	s.Push(6)
	s.Push(7)
	s.Push(5)
	s.Push(9)
	s.Push(3)
	fmt.Println(s.GetMin())
	s.Pop()
	s.Pop()
	s.Pop()
	fmt.Println(s.GetMin())
}
