package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	ErrorOutofBound = errors.New("index out of bound")
	ErrorRemove     = errors.New("remove error")
)

type Node struct {
	Data int
	Next *Node
}

type List struct {
	size  int
	begin *Node
	end   *Node
}

func New() *List {
	ll := &List{0, nil, nil}
	return ll.init()
}

func (ll *List) init() *List {
	ll.begin = &Node{0, nil}
	ll.end = &Node{0, nil}
	ll.begin.Next = ll.end
	ll.size = 0
	return ll
}

//Container
func (ll *List) Empty() bool {
	return ll.size == 0
}

func (ll *List) Size() int {
	return ll.size
}

func (ll *List) Clear() {
	ll.size = 0
	ll.init()
}

func (ll *List) Values() []int {
	values := make([]int, ll.size, ll.size)
	for i, n := 0, ll.begin.Next; n != ll.end; i, n = i+1, n.Next {
		values[i] = n.Data
	}
	return values
}

//List APIs
func (ll *List) Get(idx int) (int, bool) {
	p, err := ll.GetNode(idx)
	if err != nil {
		return -1, false
	}
	return p.Data, true
}

func (ll *List) Add(value int) {
	ll.addAfter(ll.Size()-1, value)
}

func (ll *List) addAfter(idx int, value int) {
	p, err := ll.GetNode(idx)
	if err != nil {
		fmt.Println("error get node ", idx)
		return
	}
	newNode := &Node{Data: value, Next: p.Next}
	p.Next = newNode
	ll.size++
}

func (ll *List) String() string {
	var str string
	values := []string{}
	for n := ll.begin.Next; n != ll.end; n = n.Next {
		values = append(values, fmt.Sprintf("%v", n.Data))
	}
	str += strings.Join(values, "->")
	return str
}

func (ll *List) GetNode(idx int) (node *Node, err error) {
	return ll.getNode(idx, 0, ll.Size()-1)
}

func (ll *List) getNode(idx, lower, upper int) (node *Node, err error) {
	if idx == -1 {
		return ll.begin, nil
	}

	if !ll.withinRange(idx) {
		return nil, ErrorOutofBound
	}

	p := ll.begin.Next
	for i := 0; i < idx; i, p = i+1, p.Next {
	}

	return p, nil
}

func (ll *List) withinRange(index int) bool {
	return index >= 0 && index < ll.Size()
}

func (ll *List) Reverse(gap int) {
	l := ll.Size()
	m := 0
	n := gap
	for n+gap < l {
		ll.ReverseMN(m, n)
		m = m + gap
		n = n + gap
	}
}

func (ll *List) ReverseMN(m int, n int) {
	start := ll.begin
	end := ll.begin

	for i := 0; i < m-1; i++ {
		start = start.Next
	}

	for j := 0; j < n; j++ {
		end = end.Next
	}

	preNode := start        //previous node
	curNode := preNode.Next //current node
	nexNode := curNode.Next //next node

	//Reverse before position m
	for i := 0; i < m-n-1; i++ {
		curNode.Next = preNode
		nexNode.Next = curNode
		preNode = curNode
		curNode = nexNode
		nexNode = nexNode.Next
	}

	start.Next = nexNode
}

func main() {
	//Read the input
	text := bufio.NewScanner(os.Stdin)
	fmt.Println("Please input the list length: ")
	text.Scan()
	m, _ := strconv.Atoi(text.Text())
	fmt.Println("Please input the reverse position: ")
	text.Scan()
	n, _ := strconv.Atoi(text.Text())
	if m < n {
		fmt.Println("Fatal error: select position not exist")
		return
	}

	//Build the list
	l := New()
	for i := 1; i < m+1; i++ {
		l.Add(i)
	}

	//Show the original list
	fmt.Println("Previous list is: ")
	fmt.Println(l.String())

	//Perform the reverse
	l.Reverse(n)

	//Show the list after reverse
	fmt.Println("Afterward list is: ")

}
