package arraylist

import (
	"book/GoDS/list"
	"book/GoDS/utils"
	"fmt"
	"strings"
)

func assertListImplementation() {
	var _ list.List = (*List)(nil)
}

const (
	growthFactor = float32(2.0)
	shrinkFactor = float32(0.25)
)

type List struct {
	elements []interface{}
	size     int
}

func New() *List {
	return &List{}
}

//Container
// Empty() bool
// Size() int
// Clear()
// Values() []interface{}
func (l *List) Empty() bool {
	return l.size == 0
}

func (l *List) Size() int {
	return l.size
}

func (l *List) Clear() {
	l.size = 0
	l.elements = []interface{}{}
}

func (l *List) Values() []interface{} {
	newElements := make([]interface{}, l.size, l.size)
	copy(newElements, l.elements[:l.size])
	return newElements
}

// List
//	Get(index int) (interface{}, bool)
//	Remove(index int)
//	Add(values ...interface{}) bool
//	Contains(values ...interface{}) bool
//	Sort(comparator utils.Comparator)
//	Swap(index1, index2 int)
//	Insert(index int, values ...interface{})

func (l *List) Get(index int) (interface{}, bool) {
	if !l.withinRange(index) {
		return nil, false
	}
	return l.elements[index], true
}

func (l *List) Remove(index int) {
	if !l.withinRange(index) {
		return
	}

	l.elements[index] = nil
	copy(l.elements[index:], l.elements[index+1:l.size])
	l.size--

	l.shrink()
}

func (l *List) Add(values ...interface{}) {
	l.growBy(len(values))
	for _, value := range values {
		l.elements[l.size] = value
		l.size++
	}
}

func (l *List) Contains(values ...interface{}) bool {
	for _, searchValue := range values {
		found := false
		for _, element := range l.elements {
			if element == searchValue {
				found = true
				break
			}
		}
		if !found {
			return false
		}
	}
	return true
}

func (l *List) Sort(comparator utils.Comparator) {
	if len(l.elements) < 2 {
		return
	}
	utils.Sort(l.elements[:l.size], comparator)
}

func (l *List) Swap(i, j int) {
	if l.withinRange(i) && l.withinRange(j) {
		l.elements[i], l.elements[j] = l.elements[j], l.elements[i]
	}
}

func (l *List) Insert(index int, values ...interface{}) {
	if !l.withinRange(index) {
		if index == l.size {
			l.Add(values...)
		}
		return
	}

	length := len(values)
	l.growBy(length)
	l.size += length

	//shift old to right
	for i := l.size - 1; i >= index+1; i-- {
		l.elements[i] = l.elements[i-1]
	}

	//insert new
	for i, value := range values {
		l.elements[index+i] = value
	}
}

// widget functions
func (l *List) resize(c int) {
	newElements := make([]interface{}, c, c)
	copy(newElements, l.elements)
	l.elements = newElements
}

func (l *List) growBy(n int) {
	currentCapacity := cap(l.elements)
	if l.size+n >= currentCapacity {
		newCapacity := int(growthFactor * float32(currentCapacity+n))
		l.resize(newCapacity)
	}
}

func (l *List) withinRange(index int) bool {
	return index >= 0 && index < l.size
}

func (l *List) shrink() {
	if shrinkFactor == 0.0 {
		return
	}

	currentCapacity := cap(l.elements)
	if l.size <= int(float32(currentCapacity)*shrinkFactor) {
		l.resize(l.size)
	}
}

// support func
func (l *List) String() string {
	str := "ArrayList\n"
	values := []string{}
	for _, value := range l.elements[:l.size] {
		values = append(values, fmt.Sprintf("%v", value))
	}
	str += strings.Join(values, ", ")
	return str
}
