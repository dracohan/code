// 给定一个整数数组 nums?和一个整数目标值 target，请你在该数组中找出 和为目标值
// 的那?两个?整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

// 你可以按任意顺序返回答案。

// ?

// 示例 1：

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：

// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：

// 输入：nums = [3,3], target = 6
// 输出：[0,1]

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ori_nums = nums;
    std::sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0, j = nums.size() - 1; i < j;) {
      if ((nums[i] + nums[j]) > target) {
        j--;
      } else if ((nums[i] + nums[j]) < target) {
        i++;
      } else {
        for (int n = 0; n < nums.size(); n++) {
          if (ori_nums[n] == nums[i]) res.push_back(n);
          else if (ori_nums[n] == nums[j]) res.push_back(n);
        }
        return res;
      }
    }
    return res;
  }
};

int main() {
  // vector<int> test = {3, 2, 4};
  vector<int> test = {3, 3};
  vector<int> res = Solution::twoSum(test, 6);
  // for (auto a : res) std::cout << a << std::endl;
}
