package avltree

import (
	"book/GoDS/tree"
	"book/GoDS/utils"
	"errors"
	"fmt"
)

const ALLOWED_IMBALANCE = 1

func assertTreeImplementation() {
	var _ tree.Tree = new(AvlTree)
}

type AvlTree struct {
	Root       *Node
	Comparator utils.Comparator
	size       int
}

type Node struct {
	data   interface{}
	left   *Node
	right  *Node
	height int
}

func NewWithIntComparator() *AvlTree {
	return &AvlTree{Root: nil, Comparator: utils.IntComparator, size: 0}
}

func (n *Node) Height() int {
	if n == nil {
		return -1
	}
	return n.height
}

func (at *AvlTree) Clear() {
	at.Root = nil
}

func (at *AvlTree) Values() []interface{} {
	return make([]interface{}, 0)
}

func (at *AvlTree) Empty() bool {
	return at.Root == nil
}

func (at *AvlTree) Size() int {
	return at.size
}

func (at *AvlTree) Insert(x interface{}) {
	at.Root = at.insert(x, at.Root)
}

func (at *AvlTree) Remove(x interface{}) {
	at.Root = at.remove(x, at.Root)
}

func (at *AvlTree) FindMin() interface{} {
	if at.Empty() {
		return errors.New("empty avltree")
	}
	return at.findMin(at.Root)
}

func (at *AvlTree) FindMax() interface{} {
	if at.Empty() {
		return errors.New("empty avltree")
	}
	return at.findMax(at.Root)
}

func (at *AvlTree) findMin(n *Node) interface{} {
	if n != nil {
		for n.left != nil {
			n = n.left
		}
	}
	return n.data
}

func (at *AvlTree) findMax(n *Node) interface{} {
	if n != nil {
		for n.right != nil {
			n = n.right
		}
	}
	return n.data
}

func (at *AvlTree) insert(x interface{}, n *Node) *Node {
	if n == nil {
		at.size++
		return &Node{data: x, left: nil, right: nil}
	}

	compareResult := at.Comparator(x, n.data)
	if compareResult < 0 {
		n.left = at.insert(x, n.left)
	} else if compareResult > 0 {
		n.right = at.insert(x, n.right)
	} else {
		//duplicate, do nothing
	}

	return at.balance(n)
}

func (at *AvlTree) remove(x interface{}, n *Node) *Node {
	if at.Root == nil {
		return &Node{data: x, left: nil, right: nil}
	}

	compareResult := at.Comparator(x, n.data)
	if compareResult < 0 {
		n.left = at.remove(x, n.left)
	} else if compareResult > 0 {
		n.right = at.remove(x, n.right)
	} else if n.left != nil && n.right != nil {
		//found
		n.data = at.findMin(n.right)
		n.right = at.remove(n.data, n.right)
	} else if n.left != nil {
		n = n.left
	} else {
		n = n.right
	}

	return at.balance(n)
}

func (at *AvlTree) balance(n *Node) *Node {
	if n == nil {
		return n
	}
	if n.left.Height()-n.right.Height() > ALLOWED_IMBALANCE {
		if n.left.left.Height() >= n.left.right.Height() {
			n = at.rotateWithLeftChild(n)
		} else {
			n = at.doubleWithLeftChild(n)
		}
	} else if n.right.Height()-n.left.Height() > ALLOWED_IMBALANCE {
		if n.right.right.Height() >= n.right.left.Height() {
			n = at.rotateWithRightChild(n)
		} else {
			n = at.doubleWithRightChild(n)
		}
	}
	n.height = Max(n.left.Height(), n.right.Height()) + 1
	return n
}

func (at *AvlTree) rotateWithLeftChild(k2 *Node) *Node {
	k1 := k2.left
	k2.left = k1.right
	k1.right = k2
	k2.height = Max(k2.left.Height(), k2.right.Height()) + 1
	k1.height = Max(k1.left.Height(), k2.Height()) + 1
	return k1
}

func (at *AvlTree) rotateWithRightChild(k2 *Node) *Node {
	k1 := k2.right
	k2.right = k1.left
	k1.left = k2
	k2.height = Max(k2.left.Height(), k2.right.Height()) + 1
	k1.height = Max(k1.right.Height(), k2.Height()) + 1
	return k1
}

func (at *AvlTree) doubleWithLeftChild(k3 *Node) *Node {
	k3.left = at.rotateWithRightChild(k3.left)
	return at.rotateWithLeftChild(k3)
}

func (at *AvlTree) doubleWithRightChild(k3 *Node) *Node {
	k3.right = at.rotateWithLeftChild(k3.right)
	return at.rotateWithRightChild(k3)
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func (at *AvlTree) Contains(x interface{}) bool {
	return at.contains(x, at.Root)
}

func (at *AvlTree) contains(x interface{}, n *Node) bool {
	if n == nil {
		return false
	}

	compareResult := at.Comparator(x, n.data)
	if compareResult < 0 {
		return at.contains(x, n.left)
	} else if compareResult > 0 {
		return at.contains(x, n.right)
	} else {
		return true
	}
	return false
}

func (at *AvlTree) printTree(n *Node) {
	if n != nil {
		at.printTree(n.left)
		fmt.Println(n.data)
		at.printTree(n.right)
	}
}

func (at *AvlTree) PrintTree() {
	at.printTree(at.Root)
}
