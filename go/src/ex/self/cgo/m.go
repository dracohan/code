package main

/*
#include <stdio.h>
#include <stdlib.h>
*/
import "C"

import (
	"fmt"
)

func main() {
	fmt.Println("go")
	fmt.Println(C.rand())
}
