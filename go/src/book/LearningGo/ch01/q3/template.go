package main

import (
	"fmt"
)

type I interface {
	boo()
}

type S struct {
	name string
	age  int
}

func (s S) boo() {
	fmt.Println("boo()")
}

func main() {
	fmt.Println("---------start----------")
	s := S{}
	var i I
	i = s
	i.boo()
	fmt.Println("---------end----------")
	var ss string
	for i := 0; i < 11; i++ {
		ss = ss + "A"
		fmt.Println(ss)
	}

	test := "asSASA ddd dsjkdsjs dk"
	var res map[rune]int
	res = make(map[rune]int)
	for _, r := range test {
		res[r]++
	}
	for j, k := range res {
		fmt.Printf("%c: %d\n", j, k)
	}
	runes := []rune(test)
	copy(runes[4:4+3], []rune("abc"))
	fmt.Println(string(runes))
	teststring := "foobar"
	testrune := []rune(teststring)
	for l, m := 0, len(teststring)-1; l < m; l, m = l+1, m-1 {
		testrune[l], testrune[m] = testrune[m], testrune[l]
	}
	fmt.Println(string(testrune))
}
