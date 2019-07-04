package main

import "fmt"

type Base struct {
}

func (b *Base) Func1() {
	fmt.Println("Base.Func1() was invoked!")
}

func (b *Base) Func2() {
	fmt.Println("Base.Func2() was invoked!")
}

type Derived struct {
	Base
}

func (d *Derived) Func2() {
	fmt.Println("Derived.Func2() was invoked!")
}

func (d *Derived) Func3() {
	fmt.Println("Derived.Func3() was invoked!")
}

func main() {
	d := &Derived{}
	d.Func1()      // Base.Func1() was invoked!
	d.Base.Func1() // Base.Func1() was invoked!

	d.Func2()      // Derived.Func2() was invoked!
	d.Base.Func2() // Base.Func2() was invoked!

	d.Func3() // Derived.Func3() was invoked!

	var b *Base = &Derived{}
	b.Func1()

}
