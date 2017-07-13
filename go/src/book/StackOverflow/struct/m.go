package main

import (
	"fmt"
	"unsafe"
)

type User struct {
	name string
}

func (u User) Name() string {
	return u.name
}

func (u *User) SetName(newName string) {
	u.name = newName
}

type Request struct {
	Resource string
}

type AuthenticatedRequest struct {
	Request
	Username, Password string
}

func f() {
	fmt.Println("------------------")
	data := struct {
		number int
		Text   string
	}{
		42,
		"hello",
	}

	fmt.Printf("%v\n", data)
	fmt.Println("------------------")
	var me User
	me.SetName("JM Han")
	fmt.Println("My name is: ", me.Name())
	fmt.Println("------------------")
	ar := new(AuthenticatedRequest)
	ar.Resource = "example.com/request"
	ar.Username = "bob"
	ar.Password = "P@ssw0rd"
	fmt.Printf("%#v\n", ar)
	fmt.Printf("%v\n", ar)
	fmt.Println("------------------")
	//	type T struct {
	//		I int
	//		S string
	//	}

	//	// initialize a struct
	//	t := T{1, "one"}

	//	// make struct copy
	//	u := t // u has its field values equal to t

	//	if u == t { // true
	//		fmt.Println("u and t are equal") // Prints: "u and t are equal"
	//	}
	fmt.Println("------------------")
	type T struct {
		I  int
		S  string
		xs []int // a slice is a reference type
	}
	// initialize a struct
	t := T{I: 1, S: "one", xs: []int{1, 2, 3}}

	// make struct copy
	u := t // u has its field values equal to t
	// update a slice field in u
	u.xs[1] = 500

	fmt.Printf("t.xs = %d, u.xs = %d\n", t.xs, u.xs)
	// t.xs = [1 500 3], u.xs = [1 500 3]
	fmt.Println("------------------")
	var s struct{}
	fmt.Println("size of s: %d", unsafe.Sizeof(s))
	fmt.Println("------------------")
}
