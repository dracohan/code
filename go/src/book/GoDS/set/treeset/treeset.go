package treeset

import (
	"book/GoDS/set"
	"book/GoDS/tree/avltree"
	"book/GoDS/utils"
	"fmt"
	"strings"
)

func assertSetImplementation() {
	var _ set.Set = (*Set)(nil)
}

//TODO replace AvlTree with redblackTree
type TreeSet struct {
	tree *avltree.AvlTree
}

var itemExists = struct{}{}

func NewWith(comparator utils.Comparator) *TreeSet {
	return &TreeSet{tree: avltree.NewWith(comparator)}
}

func NewWithIntComparator() *TreeSet {
	return &TreeSet{tree: avltree.NewWithIntComparator(comparator)}
}

func NewWithStringComparator() *TreeSet {
	return &TreeSet{tree: avltree.NewWithStringComparator(comparator)}
}

func (ts *TreeSet) Add(items ...interface{}) {
	for _, item := range items {
		ts.tree.Insert(item)
	}
}
