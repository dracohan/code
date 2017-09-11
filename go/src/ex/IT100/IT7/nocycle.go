package main

type node struct {
	data int
	next *node
}

func isJoinedSimple(n1, n2 *node) {
	for n1.next != nil {
		n1 = n1.next
	}
	for n2.next != nil {
		n2 = n2.next
	}
	return n1 == n2
}
