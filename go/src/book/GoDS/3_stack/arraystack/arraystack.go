package arraystack

import (
	"book/GoDS/2_list/arraylist"
	"book/GoDS/3_stack"
	"fmt"
	"strings"
)

func assertStackImplementation() {
	var _ stack.Stack = (*Stack)(nil)
}

type Stack struct {
	list *arraylist.List
}

func New() *Stack {
	return &Stack{list: arraylist.New()}
}

func (stack *Stack) Push(value interface{}) {
	stack.list.Add(value)
}

func (stack *Stack) Pop() (value interface{}, ok bool) {
	value, ok = stack.list.Get(stack.list.Size() - 1)
	stack.list.Remove(stack.list.Size() - 1)
	return
}

func (stack *Stack) Peek() (value interface{}, ok bool) {
	return stack.list.Get(stack.list.Size() - 1)
}

func (stack *Stack) Empty() bool {
	return stack.list.Empty()
}

func (stack *Stack) Size() int {
	return stack.list.Size()
}

func (stack *Stack) Clear() {
	stack.list.Clear()
}

func (stack *Stack) Values() []interface{} {
	size := stack.list.Size()
	elements := make([]interface{}, size, size)
	for i := 1; i <= size; i++ {
		elements[size-i], _ = stack.list.Get(i - 1) // in reverse (LIFO)
	}
	return elements
}

func (stack *Stack) String() string {
	values := []string{}
	for _, value := range stack.list.Values() {
		values = append(values, fmt.Sprintf("%v", value))
	}
	return strings.Join(values, ", ")
}

func (stack *Stack) withinRange(index int) bool {
	return index >= 0 && index < stack.list.Size()
}
