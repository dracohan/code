// 29.栈的push、pop序列（栈）
// 题目：输入两个整数序列。其中一个序列表示栈的push顺序，
// 判断另一个序列有没有可能是对应的pop顺序。
// 为了简单起见，我们假设push序列的任意两个整数都是不相等的。

// 比如输入的push序列是1、2、3、4、5，那么4、5、3、2、1就有可能是一个pop系列。
// 因为可以有如下的push和pop序列：
// push 1，push 2，push 3，push 4，pop，push 5，pop，pop，pop，pop，
// 这样得到的pop序列就是4、5、3、2、1。
// 但序列4、3、5、1、2就不可能是push序列1、2、3、4、5的pop序列。
// ---------------------
// 作者：v_JULY_v
// 来源：CSDN
// 原文：https://blog.csdn.net/v_july_v/article/details/6057286
// 版权声明：本文为博主原创文章，转载请附上博文链接！
package main

import (
	"fmt"
)

type stack struct {
	sl []int
}

func (s *stack) push(i int) {
	s.sl = append(s.sl, i)
}

func (s *stack) pop() int {
	r := s.sl[len(s.sl)-1]
	s.sl = s.sl[:len(s.sl)-1]
	return r
}

func main() {
	fmt.Println("gogogo")
	s := &stack{}
	for i := 0; i < 10; i++ {
		s.push(i)
	}

}
