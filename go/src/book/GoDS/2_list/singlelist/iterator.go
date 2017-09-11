package singlelist

import "book/GoDS/0_containers"

func assertIteratorImplementation() {
	var _ containers.IteratorWithIndex = (*Iterator)(nil)
}

type Iterator struct {
	list  *List
	index int
	node  *Node
}

func (list *List) Iterator() Iterator {
	return Iterator{list: list, index: -1, node: list.begin}
}

func (iterator *Iterator) Next() bool {
	if iterator.index < iterator.list.size {
		iterator.index++
	}
	if !iterator.list.withinRange(iterator.index) {
		iterator.node = nil
		return false
	}
	iterator.node = iterator.node.next
	return true
}

func (iterator *Iterator) Value() interface{} {
	return iterator.node.data
}

func (iterator *Iterator) Index() int {
	return iterator.index
}

func (iterator *Iterator) Begin() {
	iterator.index = -1
	iterator.node = iterator.list.begin
}

func (iterator *Iterator) First() bool {
	iterator.Begin()
	return iterator.Next()
}
