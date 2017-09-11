package utils

import (
	"errors"
)

var (
	ErrorOutofBound = errors.New("index out of bound")
	ErrorRemove     = errors.New("remove error")
)
