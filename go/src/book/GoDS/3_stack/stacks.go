package stack

import (
	"book/GoDS/0_containers"
)

type Stack interface {
	Push(value interface{})
	Pop() (value interface{}, ok bool)
	Peek() (value interface{}, ok bool)

	containers.Container
	//	Empty() bool
	//	Size() int
	//	Clear()
	//	Values() []interface{}
}
