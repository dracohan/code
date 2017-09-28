package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	//Compare
	fmt.Println("Compare:")
	fmt.Println(strings.Compare("a", "b"))
	fmt.Println(strings.Compare("a", "a"))
	fmt.Println(strings.Compare("b", "a"))
	fmt.Println("")

	//Contains
	fmt.Println("Contains:")
	fmt.Println(strings.Contains("seefood", "foo"))
	fmt.Println(strings.Contains("seefood", "bar"))
	fmt.Println(strings.Contains("seefood", ""))
	fmt.Println(strings.Contains("", ""))
	fmt.Println("")

	//ContainsAny
	fmt.Println("ContainsAny:")
	fmt.Println(strings.ContainsAny("team", "i"))
	fmt.Println(strings.ContainsAny("failure", "u & i"))
	fmt.Println(strings.ContainsAny("foo", ""))
	fmt.Println(strings.ContainsAny("", ""))
	fmt.Println("")

	//ContainRune
	fmt.Println("ContainRune:")
	// Finds whether a string contains a particular Unicode code point.
	// The code point for the lowercase letter "a", for example, is 97.
	fmt.Println(strings.ContainsRune("aardvark", 97))
	fmt.Println(strings.ContainsRune("timeout", 97))
	fmt.Println("")

	//Count
	fmt.Println("Count:")
	fmt.Println(strings.Count("cheese", "e"))
	fmt.Println(strings.Count("five", "")) // before & after each rune
	fmt.Println("")

	//EqualFold
	fmt.Println("EqualFold:")
	fmt.Println(strings.EqualFold("Go", "go"))
	fmt.Println("")

	//Fields
	fmt.Println("Fields:")
	fmt.Printf("Fields are: %q\n", strings.Fields("  foo bar  baz   "))
	fmt.Println("")

	//FieldsFunc
	fmt.Println("FieldsFunc:")
	f := func(c rune) bool {
		return !unicode.IsLetter(c) && !unicode.IsNumber(c)
	}
	fmt.Printf("Fields are: %q\n", strings.FieldsFunc("  foo1;bar2,baz3...", f))
	fmt.Println("")

	//HasPrefix
	fmt.Println("HasPrefix:")
	fmt.Println(strings.HasPrefix("Gopher", "Go"))
	fmt.Println(strings.HasPrefix("Gopher", "C"))
	fmt.Println(strings.HasPrefix("Gopher", ""))
	fmt.Println("")

	//HasSuffix
	fmt.Println("HasSuffix:")
	fmt.Println(strings.HasSuffix("Amigo", "go"))
	fmt.Println(strings.HasSuffix("Amigo", "O"))
	fmt.Println(strings.HasSuffix("Amigo", "Ami"))
	fmt.Println(strings.HasSuffix("Amigo", ""))
	fmt.Println("")

	//Index
	fmt.Println("Index:")
	fmt.Println(strings.Index("chicken", "ken"))
	fmt.Println(strings.Index("chicken", "dmr"))
	fmt.Println("")

	//IndexAny
	fmt.Println("IndexAny:")
	fmt.Println(strings.IndexAny("chicken", "aeiouy"))
	fmt.Println(strings.IndexAny("crwth", "aeiouy"))
	fmt.Println("")

	//IndexByte
	fmt.Println("IndexByte:")
	fmt.Println(strings.IndexByte("golang", 'g'))
	fmt.Println(strings.IndexByte("gophers", 'h'))
	fmt.Println(strings.IndexByte("golang", 'x'))
	fmt.Println("")

	//IndexFunc
	fmt.Println("IndexFunc:")
	f1 := func(c rune) bool {
		return unicode.Is(unicode.Han, c)
	}
	fmt.Println(strings.IndexFunc("Hello, 世界", f1))
	fmt.Println(strings.IndexFunc("Hello, world", f1))
	fmt.Println("")

	//IndexRune
	fmt.Println("IndexRune:")
	fmt.Println(strings.IndexRune("chicken", 'k'))
	fmt.Println(strings.IndexRune("chicken", 'd'))
	fmt.Println("")

	//Join
	fmt.Println("Join:")
	s := []string{"foo", "bar", "baz"}
	fmt.Println(strings.Join(s, ", "))
	fmt.Println("")

	//LastIndex
	fmt.Println("LastIndex:")
	fmt.Println(strings.Index("go gopher", "go"))
	fmt.Println(strings.LastIndex("go gopher", "go"))
	fmt.Println(strings.LastIndex("go gopher", "rodent"))
	fmt.Println("")

	//LastIndexAny
	fmt.Println("LastIndexAny:")
	fmt.Println(strings.LastIndexAny("go gopher", "go"))
	fmt.Println(strings.LastIndexAny("go gopher", "rodent"))
	fmt.Println(strings.LastIndexAny("go gopher", "fail"))
	fmt.Println("")

	//Map
	fmt.Println("Map:")
	rot13 := func(r rune) rune {
		switch {
		case r >= 'A' && r <= 'Z':
			return 'A' + (r-'A'+13)%26
		case r >= 'a' && r <= 'z':
			return 'a' + (r-'a'+13)%26
		}
		return r
	}
	fmt.Println(strings.Map(rot13, "'Twas brillig and the slithy gopher..."))
	fmt.Println("")

	//Repeat
	fmt.Println("Repeat:")
	fmt.Println("ba" + strings.Repeat("na", 2))
	fmt.Println("")

	//Replace
	fmt.Println("Replace:")
	fmt.Println(strings.Replace("oink oink oink", "k", "ky", 2))
	fmt.Println(strings.Replace("oink oink oink", "oink", "moo", -1))
	fmt.Println("")

	//Split
	fmt.Println("Split:")
	fmt.Printf("%q\n", strings.Split("a,b,c", ","))
	fmt.Printf("%q\n", strings.Split("a man a plan a canal panama", "a "))
	fmt.Printf("%q\n", strings.Split(" xyz ", ""))
	fmt.Printf("%q\n", strings.Split("", "Bernardo O'Higgins"))
	fmt.Println("")

	//SplitAfter
	fmt.Println("SplitAfter:")
	fmt.Printf("%q\n", strings.SplitAfter("a,b,c", ","))
	fmt.Println("")

	//SplitAfterN
	fmt.Println("SplitAfterN:")
	fmt.Printf("%q\n", strings.SplitAfterN("a,b,c", ",", 2))
	fmt.Println("")

	//SplitN
	fmt.Println("SplitN:")
	fmt.Printf("%q\n", strings.SplitN("a,b,c", ",", 2))
	z := strings.SplitN("a,b,c", ",", 0)
	fmt.Printf("%q (nil = %v)\n", z, z == nil)
	fmt.Println("")

	//Title
	fmt.Println("Title:")
	fmt.Println(strings.Title("her royal highness"))
	fmt.Println("")

	//ToLower
	fmt.Println("ToLower:")
	fmt.Println(strings.ToLower("Gopher"))
	fmt.Println("")

	//ToTitle
	fmt.Println("ToTitle:")
	fmt.Println(strings.ToTitle("loud noises"))
	fmt.Println(strings.ToTitle("хлеб"))
	fmt.Println("")

	//ToUpper
	fmt.Println("ToUpper:")
	fmt.Println(strings.ToUpper("Gopher"))
	fmt.Println("")

	//Trim
	fmt.Println("Trim:")
	fmt.Printf("[%q]", strings.Trim(" !!! Achtung! Achtung! !!! ", "! "))
	fmt.Println("")

	//TrimFunc
	fmt.Println("TrimFunc:")
	f2 := func(c rune) bool {
		return !unicode.IsLetter(c) && !unicode.IsNumber(c)
	}
	fmt.Printf("[%q]", strings.TrimFunc("  Achtung1! Achtung2,...", f2))
	fmt.Println("")

	//TrimPrefix
	fmt.Println("TrimPrefix:")
	var ss = "Goodbye,, world!"
	ss = strings.TrimPrefix(ss, "Goodbye,")
	ss = strings.TrimPrefix(ss, "Howdy,")
	fmt.Print("Hello" + ss)
	fmt.Println("")

	//TrimSpace
	fmt.Println("TrimSpace:")
	fmt.Println(strings.TrimSpace(" \t\n a lone gopher \n\t\r\n"))
	fmt.Println("")

	//TrimSpace
	fmt.Println("TrimSpace:")
	var sss = "Hello, goodbye, etc!"
	sss = strings.TrimSuffix(sss, "goodbye, etc!")
	sss = strings.TrimSuffix(sss, "planet")
	fmt.Print(sss, "world!")
	fmt.Println("")

	//NewReplacer
	fmt.Println("NewReplacer:")
	r := strings.NewReplacer("<", "&lt;", ">", "&gt;")
	fmt.Println(r.Replace("This is <b>HTML</b>!"))
	fmt.Println("")

}
