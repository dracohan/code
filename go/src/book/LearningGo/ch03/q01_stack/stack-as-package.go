package stack

// 保存元素的Stack
type Stack struct {
	i    int
	data [10]int
}

// Push 将元素􀴺入栈中
func (s *Stack) Push(k int) {
	s.data[s.i] = k
	s.i++
}

// Pop 从栈中􁣨出一个元素
func (s *Stack) Pop() (ret int) {
	s.i--
	ret = s.data[s.i]
	return
}
