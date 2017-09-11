package bstree

import (
	"book/GoDS/tree"
	"book/GoDS/utils"
)

func assertTreeImplementation() {
	var _ tree.Tree = (*BSTree)(nil)
}

type Node struct {
	data  interface{}
	left  *Node
	right *Node
}

type BSTree struct {
	root *Node
	size int
}

func New() *BSTree {
	return &BSTree{root: nil, size: 0}
}

//Container
func (t *BSTree) MakeEmpty() {
	t.root = nil
}

func (t *BSTree) Empty() bool {
	return nil == t.root
}

func (t *BSTree) Size() int {
	return t.size
}

func (t *BSTree) Clear() {
	t.size = 0
	t.root = nil
}

func (t *BSTree) Values() []interface{} {
	values := make([]interface{}, t.size)
	values = t.getValues(t.root, values)
	return values
}

func (t *BSTree) getValues(n *Node, values []interface{}) []interface{} {
	if n != nil {
		values = append(values, t.getValues(n.left, values))
		values = append(values, n.data)
		values = append(values, t.getValues(n.right, values))
	}
	return values
}

func (t *BSTree) Contains(x interface{}) bool {
	return t.contains(x, t.root)
}

func (t *BSTree) contains(x interface{}, root *Node) bool {
	if x == nil {
		return false
	}

	comparableResult := utils.IntComparator(x, root.data)

	if comparableResult < 0 {
		return t.contains(x, root.left)
	} else if comparableResult > 0 {
		return t.contains(x, root.right)
	} else {
		return true
	}
}

func (t *BSTree) FindMin() int {
	if t.Empty() {
		return -1
	}
	return t.findMin(t.root).data.(int)
}

func (t *BSTree) FindMax() int {
	if t.Empty() {
		return -1
	}
	n := t.findMax(t.root)
	return n.data.(int)
}

func (t *BSTree) findMin(n *Node) *Node {
	if n == nil {
		return nil
	} else if n.left == nil {
		return n
	}
	return t.findMin(n.left)

}

func (t *BSTree) findMax(n *Node) *Node {
	if n != nil {
		for n.right != nil {
			n = n.right
		}
	}
	return n
}

func (t *BSTree) Insert(x interface{}) {
	t.root = t.insert(x, t.root)
}

func (t *BSTree) insert(x interface{}, n *Node) *Node {
	if n == nil {
		t.size++
		return &Node{data: x.(int), left: nil, right: nil}
	}

	comparableResult := utils.IntComparator(x, n.data)
	if comparableResult < 0 {
		n.left = t.insert(x, n.left)
	} else if comparableResult > 0 {
		n.right = t.insert(x, n.right)
	}
	return n
}

func (t *BSTree) Remove(x interface{}) {
	t.root = t.remove(x, t.root)
	t.size--
}

func (t *BSTree) remove(x interface{}, n *Node) *Node {
	if n == nil {
		return n
	}

	comparableResult := utils.IntComparator(x, n.data)
	if comparableResult < 0 {
		n.left = t.remove(x, n.left)
	} else if comparableResult > 0 {
		n.right = t.remove(x, n.right)
	} else if n.left != nil && n.right != nil {
		n.data = t.findMin(n.right).data
		n.right = t.remove(n.data, n.right)
	} else if n.left != nil {
		n = n.left
	} else if n.right != nil {
		n = n.right
	} else {
		n = nil
	}
	return n
}

func (t *BSTree) PrintTree() {
	if t.Empty() {
		print("Empty Tree")
	} else {
		t.printTree(t.root)
	}
}

func (t *BSTree) printTree(n *Node) {
	if n != nil {
		t.printTree(n.left)
		print(n.data.(int), "\n")
		t.printTree(n.right)
	}
}
