package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scn := bufio.NewScanner(os.Stdin)
	for {
		var lines []string
		for scn.Scan() {
			line := scn.Text()
			if len(line) == 1 {
				if line[0] == '\x1D' {
					break
				}
			}
			if len(line) == 0 {
				break
			}
			lines = append(lines, line)
		}

		for _, line := range lines {
			str := strings.Split(line, ",")
			for i := len(str) - 1; i >= 0; i-- {
				for j := 0; j < i; j++ {
					if str[j] == str[i] {
						if i == len(str)-1 {
							str = str[:i]
							break
						} else {
							str = append(str[:i], str[i+1:]...)
							break
						}
					}
				}
			}

			fmt.Println(strings.Join(str, ","))
		}

		if len(lines) == 0 {
			break
		}
	}
}
