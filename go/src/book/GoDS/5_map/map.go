package maps

import "book/GoDS/0_containers"

type Map interface {
	Put(key interface{}, value interface{})
	Get(key interface{}) (value interface{}, found bool)
	Remove(key interface{})
	Keys() []interface{}

	containers.Container
	// Empty() bool
	// Size() int
	// Clear()
	// Values() []interface{}
}

type BidiMap interface {
	GetKey(value interface{}) (key interface{}, found bool)

	Map
}
