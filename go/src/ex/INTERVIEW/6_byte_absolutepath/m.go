package main

import (
	"fmt"
	"path/filepath"
	"strings"
)

func AbsolutePath(path string) string {
	p, err := filepath.Abs(path)
	if err != nil {
		fmt.Println(err)
	}
	i := strings.LastIndex(p, ".")
	return p[:i]
}

func main() {
	// path := `/////ab////cc////////cdd/ee////eb/b///ggg.go///`
	path1 := `\\\\abc\\adfsda\\\\\\\d\\c\\\e\c.go.gp\\d.c`
	fmt.Println(AbsolutePath(path1))

}
