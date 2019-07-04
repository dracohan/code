package main

import "fmt"

func main() {
	nums := []int{1, 2, 3, 4, 7, 11, 15}
	fmt.Println(twoSum(nums, 5))
}

func twoSum(nums []int, target int) []int {
	numsMap := make(map[int]int)
	ressMap := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		numsMap[nums[i]] = i
	}
	for i := 0; i < len(nums); i++ {
		if _, ok := numsMap[target-nums[i]]; ok && numsMap[target-nums[i]] != i {
			_, ok1 = ressMap[target-nums[i]]
			_, ok2 = ressMap[i]
			if !ok1 && ok2 {
				ressMap(numsMap[target-nums[i]]) = i
			}
		}
	}
	fmt.Println(ressMap)

	return nil
}
