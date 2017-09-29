package main

import "fmt"

type Human struct {
	name  string
	age   int
	phone string
}

func (h *Human) Call() {
	fmt.Println(h.phone)
}

type Employee struct {
	Human
	phone string
}

func (e *Employee) Call() {
	fmt.Println(e.Human.phone)
}
func main() {
	Bob := Employee{Human{"Bob", 34, "777-444"}, "333-222"}
	fmt.Println(Bob.phone)
	Bob.Call()
}
