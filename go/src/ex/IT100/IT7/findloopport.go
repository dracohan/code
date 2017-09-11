func findLoopPort(l *list) *list {
	fast := l
	slow := l
	for fast != nil && fast.next != nil {
		fast = fast.next.next
		slow = slow.next
		if fast == slow {
			break
		}
	}

	if fast == nil || slow == nil {
		return nil
	}

	slow = l
	for slow != fast {
		slow = slow.next
		fast = fast.next
	}
	return slow
}