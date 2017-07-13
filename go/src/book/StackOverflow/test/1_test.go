package main

import (
	"testing"
)

// Test methods start with `Test`
func TestSum(t *testing.T) {
	got := Sum(1, 2)
	want := 3
	if got != want {
		t.Errorf("Sum(1, 2) == %d, want %d", got, want)
	}
}

// Test methods start with Test
func TestSum1(t *testing.T) {
	// Note that the data variable is of type array of anonymous struct,
	// which is very handy for writing table-driven unit tests.
	data := []struct {
		a, b, res int
	}{
		{1, 2, 3},
		{0, 0, 0},
		{1, -1, 0},
		{2, 3, 5},
		{1000, 234, 1234},
	}

	for _, d := range data {
		if got := Sum(d.a, d.b); got != d.res {
			t.Errorf("Sum(%d, %d) == %d, want %d", d.a, d.b, got, d.res)
		}
	}
}
