package linkedliststack

import (
	"fmt"
	"strings"

	"study/datastruct-master/stacks"
	"study/datastruct/list/singlelist"
)

func assertStackImplementation() {
	var _ stacks.Stack = (*Stack)(nil)
}

type Stack struct {
	list *singlelist.List
}

func New() *Stack {
	return &Stack{list: singlelist.New()}
}

func (stack *Stack) Push(value interface{}) {
	stack.list.Prepend(value)
}

func (stack *Stack) Pop() (value interface{}, ok bool) {
	value, ok = stack.list.Get(0)
	stack.list.Remove(0)
	return
}

func (stack *Stack) Peek() (value interface{}, ok bool) {
	return stack.list.Get(0)
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
	return stack.list.Values()
}

func (stack *Stack) String() string {
	str := "LinkedListStack\n"
	values := []string{}
	for _, value := range stack.list.Values() {
		values = append(values, fmt.Sprintf("%v", value))
	}
	str += strings.Join(values, ", ")
	return str
}

func (stack *Stack) withinRange(index int) bool {
	return index >= 0 && index < stack.list.Size()
}
