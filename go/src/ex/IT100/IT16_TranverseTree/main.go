package main

import "fmt"

type enque struct {
	count int
	array []*node
}

func (s *enque) push(i *node) {
	s.array = append(s.array, i)
	s.count++
}

func (s *enque) pop() *node {
	if s.count > 0 {
		tmp := s.array[0]
		s.array = s.array[1:]
		s.count--
		return tmp
	}
	return nil
}

type stack struct {
	count int
	array []*node
}

func (s *stack) push(i *node) {
	s.array = append(s.array, i)
	s.count++
}

func (s *stack) pop() *node {
	if s.count > 0 {
		tmp := s.array[s.count-1]
		s.array = s.array[:s.count-1]
		s.count--
		return tmp
	}
	return nil
}

func (s *enque) display() {
	for i := 0; i < s.count; i++ {
		fmt.Println(s.array[i])
	}
}

type node struct {
	data        int
	right, left *node
}

func add(n *node, i int) *node {
	if n == nil {
		return &node{i, nil, nil}
	}
	if i > n.data {
		n.right = add(n.right, i)
	} else if i < n.data {
		n.left = add(n.left, i)
	} else {
		//dup
	}
	return n
}

func printtree(n *node) {
	if n.left != nil {
		printtree(n.left)
	}
	fmt.Println(n.data)
	if n.right != nil {
		printtree(n.right)
	}
}

func widthfirst(n *node) {
	q := &enque{}
	q.push(n)
	for q.count != 0 {
		p := q.pop()
		fmt.Println(p.data)
		if p.left != nil {
			q.push(p.left)
		}
		if p.right != nil {
			q.push(p.right)
		}
	}
}

func depthfirst(n *node) {
	s := &stack{}
	s.push(n)
	for s.count != 0 {
		p := s.pop()
		fmt.Println(p.data)
		if p.right != nil {
			s.push(p.right)
		}
		if p.left != nil {
			s.push(p.left)
		}
	}
}

func main() {
	var root *node
	t := []int{8, 10, 6, 9, 11, 5, 7}
	for _, x := range t {
		root = add(root, x)
	}
	//	widthfirst(root)
	depthfirst(root)
}
