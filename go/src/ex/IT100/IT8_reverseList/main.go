package main

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

type Node struct {
	data interface{}
	next *Node
}

type List struct {
	size  int
	begin *Node
	end   *Node
}

func New() *List {
	ll := &List{0, nil, nil}
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

//List APIs
func (ll *List) Get(idx int) (interface{}, bool) {
	p, err := ll.GetNode(idx)
	if err != nil {
		return nil, false
	}
	return p.data, true
}

func (ll *List) Remove(idx int) {
	p, err := ll.GetNode(idx - 1)
	if err != nil {
		return
	}

	ll.remove(p)
}

func (ll *List) Add(values ...interface{}) {
	for _, value := range values {
		ll.addAfter(ll.Size()-1, value)
	}
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

func (ll *List) Insert(index int, values ...interface{}) {
	if index > ll.Size() {
		return
	}
	for _, value := range values {
		ll.addBefore(index, value)
		index++
	}
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

//Append values at the end
func (ll *List) Append(values ...interface{}) {
	ll.Add(values)
}

//Insert values one by one at the beginning
func (ll *List) Prepend(values ...interface{}) {
	for v := len(values) - 1; v >= 0; v-- {
		newNode := &Node{data: values[v], next: ll.begin.next}
		ll.begin.next = newNode
		ll.size++
	}
}

func (ll *List) remove(p *Node) {
	if p.next != ll.end {
		p.next = p.next.next
		ll.size--
	}
}

func (ll *List) String() string {
	str := "SingleList: "
	values := []string{}
	for n := ll.begin.next; n != ll.end; n = n.next {
		values = append(values, fmt.Sprintf("%v", n.data))
	}
	str += strings.Join(values, ", ")
	return str
}

func (ll *List) GetNode(idx int) (node *Node, err error) {
	return ll.getNode(idx, 0, ll.Size()-1)
}

func (ll *List) getNode(idx, lower, upper int) (node *Node, err error) {
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

func (ll *List) withinRange(index int) bool {
	return index >= 0 && index < ll.Size()
}

func (ll *List) Reverse() {
	//	ll.reverseR(ll.begin)
	ll.reverseNR(ll.begin)
}

func (ll *List) reverseR(n *Node) *Node {
	if n == ll.end {
		phead := ll.begin
		ll.begin = n
		ll.end = phead
	} else {
		ll.reverseR(n.next).next = n
	}
	return n
}

func (ll *List) reverseNR(n *Node) {
	pre := ll.begin
	cur := pre.next
	var np *Node

	for cur != ll.end {
		np = cur.next
		cur.next = pre
		pre = cur
		cur = np
	}

	ll.begin = cur
	cur.next = pre

	ll.end = n
	ll.end.next = nil
}

func main() {
	l := New()
	for i := 0; i < 8; i++ {
		l.Add(i)
	}
	fmt.Println(l.String())
	l.Reverse()
	fmt.Println(l.String())

}
