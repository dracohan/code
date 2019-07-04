// 同一深度，且没有被覆盖，直接调用d.Name还是会冲突
// 但是可以使用d.Base.Name
package main

import "fmt"

type Base struct {
	Name string
}

type Base1 struct {
	Name string
}

type Derived struct {
	Base
	Base1
	// Name string
}

func main() {
	d := &Derived{}
	d.Name = "Derived"
	d.Base.Name = "Base"

	fmt.Println(d.Name)      // Derived
	fmt.Println(d.Base.Name) // Base
}
