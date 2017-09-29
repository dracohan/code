package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"unicode"
)

func main() {
	scn := bufio.NewScanner(os.Stdin)
	for scn.Scan() {
		RES := make([]string, 0)
		line := scn.Text()
		if len(line) == 1 {
			if line[0] == '\x1D' {
				break
			}
		}
		if len(line) == 0 {
			break
		}
		if !IsLetter(line) {
			fmt.Println("-1")
			continue
		}
		for i := 1; i <= len(line)/2; i++ {
			b, num := zip(line, i)
			if b == true {
				RES = append(RES, line[0:i]+strconv.Itoa(num))
			}
		}
		if len(RES) != 0 {
			fmt.Println(RES[0])
		} else {
			fmt.Println(line + strconv.Itoa(1))
		}
	}

}

func zip(line string, i int) (bool, int) {
	num := 1
	str := line[0:i]
	for len(str) < len(line) {
		str = str + line[0:i]
		if !startWithStr(str, line) {
			return false, 0
		}
		num++
	}
	return true, num

}

func IsLetter(s string) bool {
	for _, r := range s {
		if !unicode.IsLetter(r) {
			return false
		}
	}
	return true
}

func startWithStr(s, t string) bool {
	return strings.HasPrefix(t, s)
}

//func zip(s string) string {
//	rs := []rune(s)
//	var length int
//	var res []string
//	length = len(rs)
//	for i := 1; i <= len(s)/2; i++ {
//		b, num := scan(rs, rs[length-i:])
//		if b == true && num != 0 {
//			res = append(res, string(rs[length-i:])+strconv.Itoa(num))
//		}
//	}
//	if len(res) != 0 {
//		return res[len(res)-1]
//	}
//	return s
//}

//func scan(rs, target []rune) (bool, int) {
//	var num int
//	var l int
//	l = len(target)
//	for gap := l + l; gap < len(rs); gap = gap + l {
//		for i := 1; i <= l; i++ {
//			if target[l-gap+i] != target[l-gap+l+i] {
//				return false, 0
//			}
//		}
//		num++
//	}
//	return true, num
//}
