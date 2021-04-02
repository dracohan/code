// 给你一个整数数组 nums
// ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

// 示例 1：

// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subsets-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  vector<int> items;

 public:
  void subsets(vector<int>& nums, int start) {
    res.push_back(items);
    if (start >= nums.size()) return;
    for (int i = start; i < nums.size(); ++i) {
      //  if (i > start && nums[i] == nums[i - 1]) continue;
      items.push_back(nums[i]);
      subsets(nums, i + 1);
      items.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    subsets(nums, 0);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = s.subsetsWithDup(nums);
  for (auto v : res) {
    for (auto n : v) {
      std::cout << n << ", ";
    }
    std::cout << std::endl;
  }
}