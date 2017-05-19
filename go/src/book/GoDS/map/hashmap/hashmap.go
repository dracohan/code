package hashmap

import (
	"fmt"
	"study/datastruct/maps"
)

func assertMapImplementation() {
	var _ maps.Map = (*Map)(nil)
}

type Map struct {
	m map[interface{}]interface{}
}

func New() *Map {
	return &Map{m: make(map[interface{}]interface{})}
}

func (m *Map) Put(key interface{}, value interface{}) {
	m.m[key] = value
}

func (m *Map) Get(key interface{}) (value interface{}, found bool) {
	value, found = m.m[key]
	return
}

func (m *Map) Empty() bool {
	return m.Size() == 0
}

func (m *Map) Size() int {
	return len(m.m)
}

func (m *Map) Keys() []interface{} {
	keys := make([]interface{}, m.Size())
	count := 0
	for key := range m.m {
		keys[count] = key
		count++
	}
	return keys
}

func (m *Map) Values() []interface{} {
	values := make([]interface{}, m.Size())
	count := 0
	for _, value := range m.m {
		values[count] = value
		count++
	}
	return values
}

func (m *Map) Clear() {
	m.m = make(map[interface{}]interface{})
}

func (m *Map) String() string {
	str := "HashMap\n"
	str += fmt.Sprintf("%v", m.m)
	return str
}

func (m *Map) Remove(key interface{}) {
	delete(m.m, key)
}
