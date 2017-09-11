package set

import "book/GoDS/0_containers"

type Set interface {
	Add(elements ...interface{})
	Remove(elements ...interface{})
	Contains(elements ...interface{}) bool

	containers.Container
	// Empty() bool
	// Size() int
	// Clear()
	// Values() []interface{}
}
