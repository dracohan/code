package main

//import (
//	"fmt"

//	"github.com/deckarep/golang-set"
//)

//func main() {
//	kide := mapset.NewSet()
//	kide.Add("xiaorui.cc")
//	kide.Add("blog.xiaorui.cc")
//	kide.Add("vps.xiaorui.cc")
//	kide.Add("linode.xiaorui.cc")

//	special := []interface{}{"Biology", "Chemistry"}
//	scienceClasses := mapset.NewSetFromSlice(special)

//	address := mapset.NewSet()
//	address.Add("beijing")
//	address.Add("nanjing")
//	address.Add("shanghai")

//	bonusClasses := mapset.NewSet()
//	bonusClasses.Add("Go Programming")
//	bonusClasses.Add("Python Programming")

//	//一个并集的运算
//	allClasses := kide.Union(scienceClasses).Union(address).Union(bonusClasses)
//	fmt.Println(allClasses)

//	//是否包含"Cookiing"
//	fmt.Println(scienceClasses.Contains("Cooking")) //false

//	//两个集合的差集
//	fmt.Println(allClasses.Difference(scienceClasses)) //Set{Music, Automotive, Go Programming, Python Programming, Cooking, English, Math, Welding}

//	//两个集合的交集
//	fmt.Println(scienceClasses.Intersect(kide)) //Set{Biology}

//	//有多少基数
//	fmt.Println(bonusClasses.Cardinality()) //2

//}
