package arraylist

//import "book/GoDS/containers"

type Iterator struct {
	list  *List
	index int
}

func (l *List) Iterator() Iterator {
	return Iterator{list: l, index: -1}
}

func (iterator *Iterator) Next() bool {
	if iterator.index < iterator.list.size {
		iterator.index++
	}
	return iterator.list.withinRange(iterator.index)
}

func (iterator *Iterator) Prev() bool {
	if iterator.index >= 0 {
		iterator.index--
	}
	return iterator.list.withinRange(iterator.index)
}

func (iterator *Iterator) Value() interface{} {
	return iterator.list.elements[iterator.index]
}

func (iterator *Iterator) Index() int {
	return iterator.index
}

func (iterator *Iterator) Begin() {
	iterator.index = -1
}

func (iterator *Iterator) End() {
	iterator.index = iterator.list.size
}

func (iterator *Iterator) First() bool {
	iterator.Begin()
	return iterator.Next()
}

func (iterator *Iterator) Last() bool {
	iterator.End()
	return iterator.Prev()
}
