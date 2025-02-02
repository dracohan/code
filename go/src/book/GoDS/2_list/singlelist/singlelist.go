package singlelist

import (
	"book/GoDS/1_utils"
	"book/GoDS/2_list"
	"errors"
	"fmt"
	"strings"
)

var (
	ErrorOutofBound = errors.New("index out of bound")
	ErrorRemove     = errors.New("remove error")
)

func assertListImplementation() {
	var _ list.List = (*List)(nil)
}

type List struct {
	begin *Node
	end   *Node
	size  int
}

type Node struct {
	data interface{}
	next *Node
}

func New() *List {
	ll := &List{}
	return ll.init()
}

func (ll *List) init() *List {
	ll.begin = &Node{0, nil}
	ll.end = &Node{0, nil}
	ll.begin.next = ll.end
	ll.size = 0
	return ll
}

//Container
// Empty() bool
// Size() int
// Clear()
// Values() []interface{}
func (ll *List) Empty() bool {
	return ll.size == 0
}

func (ll *List) Size() int {
	return ll.size
}

func (ll *List) Clear() {
	ll.size = 0
	ll.init()
}

func (ll *List) Values() []interface{} {
	values := make([]interface{}, ll.size, ll.size)
	for i, n := 0, ll.begin.next; n != ll.end; i, n = i+1, n.next {
		values[i] = n.data
	}
	return values
}

// List
//	Get(index int) (interface{}, bool)
//	Add(values ...interface{}) bool
//	Remove(index int)
//	Contains(values ...interface{}) bool
//	Insert(index int, values ...interface{})
//	Sort(comparator utils.Comparator)
//	Swap(index1, index2 int)

func (ll *List) Get(idx int) (interface{}, bool) {
	p, err := ll.GetNode(idx)
	if err != nil {
		return nil, false
	}
	return p.data, true
}

func (ll *List) Add(values ...interface{}) {
	for _, value := range values {
		ll.addAfter(ll.Size()-1, value)
	}
}

func (ll *List) Remove(idx int) {
	p, err := ll.GetNode(idx - 1)
	if err != nil {
		return
	}
	ll.removeAfter(p)
}

func (ll *List) Contains(values ...interface{}) bool {
	for _, value := range values {
		found := false
		for node := ll.begin.next; node != ll.end; node = node.next {
			if node.data == value {
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

func (ll *List) Insert(index int, values ...interface{}) {
	if index > ll.Size() {
		return
	}
	for _, value := range values {
		ll.addBefore(index, value)
		index++
	}
}

func (ll *List) Sort(comparator utils.Comparator) {
	if ll.Size() < 2 {
		return
	}

	values := ll.Values()
	utils.Sort(values, comparator)

	ll.Clear()
	ll.Add(values)
}

func (ll *List) Swap(i, j int) {
	if ll.withinRange(i) && ll.withinRange(j) && i != j {
		var n1, n2 *Node
		for e, currentNode := 0, ll.begin.next; n1 == nil || n2 == nil; e, currentNode = e+1, currentNode.next {
			switch e {
			case i:
				n1 = currentNode
			case j:
				n2 = currentNode
			}
		}
		n1.data, n2.data = n2.data, n1.data
	}
}

// Other functions
// GetNode(idx int) (node *Node, err error)
// addAfter(idx int, value interface{})
// addBefore(idx int, value interface{})
// removeAfter(p *Node)
// withinRange(index int) bool
// Append(values ...interface{})
// Prepend(values ...interface{})
// String() string
func (ll *List) GetNode(idx int) (node *Node, err error) {
	if idx == -1 {
		return ll.begin, nil
	}

	if !ll.withinRange(idx) {
		return nil, ErrorOutofBound
	}

	p := ll.begin.next
	for i := 0; i < idx; i, p = i+1, p.next {
	}

	return p, nil
}

func (ll *List) addAfter(idx int, value interface{}) {
	p, err := ll.GetNode(idx)
	if err != nil {
		fmt.Println("error get node ", idx)
		return
	}
	newNode := &Node{data: value, next: p.next}
	p.next = newNode
	ll.size++
}

func (ll *List) addBefore(idx int, value interface{}) {
	if ll.Size() == 0 {
		newNode := &Node{data: value, next: ll.end}
		ll.begin.next = newNode
		ll.size++
		return
	}

	var p *Node
	var err error

	p, err = ll.GetNode(idx - 1)
	if err != nil {
		fmt.Println("error get node ", idx)
		return
	}

	newNode := &Node{data: value, next: p.next}
	p.next = newNode
	ll.size++
}

func (ll *List) removeAfter(p *Node) {
	if p.next != ll.end {
		p.next = p.next.next
		ll.size--
	}
}

func (ll *List) withinRange(index int) bool {
	return index >= 0 && index < ll.Size()
}

func (ll *List) Append(values ...interface{}) {
	ll.Add(values)
}

func (ll *List) Prepend(values ...interface{}) {
	for v := len(values) - 1; v >= 0; v-- {
		newNode := &Node{data: values[v], next: ll.begin.next}
		ll.begin.next = newNode
		ll.size++
	}
}

func (ll *List) String() string {
	str := "SingleList\n"
	values := []string{}
	for n := ll.begin.next; n != ll.end; n = n.next {
		values = append(values, fmt.Sprintf("%v", n.data))
	}
	str += strings.Join(values, ", ")
	return str
}
