/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.63%)
 * Likes:    1117
 * Dislikes: 0
 * Total Accepted:    305.6K
 * Total Submissions: 480.5K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums
 * ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 *
 *
 *
 *
 */
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> track;
  vector<vector<int>> result;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    backtrace(nums, 0);
    return result;
  }

  void backtrace(vector<int> &nums, int start) {
    result.push_back(track);
    for (int i = start; i < nums.size(); i++) {
      if(i > start && nums[i] == nums[i - 1]) continue;
      track.push_back(nums[i]);
      backtrace(nums, i + 1);
      track.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> c = {1, 2, 5, 2};
  vector<vector<int>> res = s.subsetsWithDup(c);
  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto tt = it->begin(); tt != it->end(); tt++) {
      std::cout << *tt << " ";
    }
    std::cout << std::endl;
  }
}
// @lc code=end
