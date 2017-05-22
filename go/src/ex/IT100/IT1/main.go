package main

import (
	"fmt"
)

type BSTreeNode struct {
	value int
	left  *BSTreeNode
	right *BSTreeNode
}

type BSTree struct {
	root *BSTreeNode
	head *BSTreeNode
	last *BSTreeNode
}

func NewTree() *BSTree {
	return &BSTree{}
}

func (bs *BSTree) Insert(value int) {
	bs.root = bs.insert(bs.root, value)
}

func (bs *BSTree) insert(t *BSTreeNode, value int) *BSTreeNode {
	if t == nil {
		return &BSTreeNode{value: value}
	}

	if t.value > value {
		t.left = bs.insert(t.left, value)
	} else if t.value < value {
		t.right = bs.insert(t.right, value)
	} else {
		print("already exist")
	}
	return t
}

func (bs *BSTree) TreeToList() {
	bs.treeToList(bs.root)
}

func (bs *BSTree) treeToList(root *BSTreeNode) {
	if nil == root {
		return
	}
	bs.treeToList(root.left)

	root.left = bs.last
	if nil == bs.last {
		bs.head = root
	} else {
		bs.last.right = root
	}
	bs.last = root
	bs.treeToList(root.right)
}

func (bs *BSTree) printList() {
	if nil == bs.head {
		return
	}
	for bs.head != nil {
		fmt.Println(bs.head.value)
		bs.head = bs.head.right
	}
}

func main() {
	bstree := NewTree()
	bstree.Insert(10)
	bstree.Insert(6)
	bstree.Insert(14)
	bstree.Insert(4)
	bstree.Insert(8)
	bstree.Insert(12)
	bstree.Insert(16)
	bstree.TreeToList()
	bstree.printList()
}
