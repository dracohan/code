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
	var start, end *Node
	if last == nil {
		//首次循环起始节点为首节点
		start = ll.begin.Next
	} else {
		//后续循环起始节点为上次结束的nNode
		start = next
	}

	//找到本次循环的末尾节点
	end = start
	for i := 0; i < gap-1 && end != ll.end; i++ {
		end = end.Next
	}

	if end != ll.end {
		//如果还有大于gap个元素，继续翻转start到end部分
		ll.ReverseGap(start, end)
	} else {
		//否则链接剩余节点后结束
		last.Next = start
		return
	}

	//继续后续gap翻转
	ll.Reverse(gap)
}

//上次遍历的首节点
var last *Node

//本次遍历的首节点
var next *Node

func (ll *List) ReverseGap(start, end *Node) {
	if last == nil {
		//首次遍历，end即为新的头节点
		ll.begin.Next = end
	} else {
		//后续遍历，end为上次遍历最后节点的Next节点
		last.Next = end
	}

	if start.Next == end {
		//gap为2
		pNode := start
		cNode := start.Next
		next = cNode.Next
		cNode.Next = pNode
		last = start
	} else {
		//gap大于2
		pNode := start
		cNode := start.Next
		nNode := start.Next.Next

		for cNode != end {
			rNode := nNode.Next
			cNode.Next = pNode
			nNode.Next = cNode
			pNode = cNode
			cNode = nNode
			nNode = rNode
		}
		last = start
		next = nNode
	}

}

func main() {
	//Read the input
	text := bufio.NewScanner(os.Stdin)
	fmt.Println("Please input the list length: ")
	text.Scan()
	n, _ := strconv.Atoi(text.Text())
	fmt.Println("Please input the reverse position: ")
	text.Scan()
	gap, _ := strconv.Atoi(text.Text())
	if gap <= 1 {
		fmt.Println("Please input gap larger than 1")
		return
	}

	//Build the list
	l := New()
	for i := 1; i < n+1; i++ {
		l.Add(i)
	}

	//Show the original list
	fmt.Println("Previous list is: ")
	fmt.Println(l.String())

	//Perform the reverse
	l.Reverse(gap)

	//Show the list after reverse
	fmt.Println("Afterward list is: ")
	fmt.Println(l.String())

}
