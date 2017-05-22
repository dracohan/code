package list

import (
	"book/GoDS/containers"
	"book/GoDS/utils"
)

type List interface {
	Get(index int) (interface{}, bool)
	Remove(index int)
	Add(values ...interface{})
	Contains(values ...interface{}) bool
	Sort(comparator utils.Comparator)
	Swap(index1, index2 int)
	Insert(index int, values ...interface{})

	containers.Container
	// Empty() bool
	// Size() int
	// Clear()
	// Values() []interface{}
}
