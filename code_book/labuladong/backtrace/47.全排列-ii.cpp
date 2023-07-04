/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (65.48%)
 * Likes:    1388
 * Dislikes: 0
 * Total Accepted:    464.9K
 * Total Submissions: 709.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // if current number(n) is previous unused one
  // it has same effect, ignore current selection
  bool findInUnselected(vector<int> nums, int n) {
    for (int i = 0; i < n; i++) {
        if (used[i] == false && nums[i] == nums[n] ) 
          return true;
    }
    return false;
  }

  void backtrace(vector<int>& nums) {
    if (track.size() == nums.size()) {
      res.push_back(track);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      // for every unselected ones
      // check and try to select
      if (used[i]) {
        continue;
      }
      if (i > 0 && findInUnselected(nums, i)) {
        continue;
      }
      track.push_back(nums[i]);
      used[i] = true;
      backtrace(nums);
      track.pop_back();
      used[i] = false;
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    used = vector<bool>(nums.size(), false);
    backtrace(nums);
    return res;
  }
  vector<vector<int>> res;
  vector<int> track;
  vector<bool> used;
};

int main() {
  Solution s;
  vector<int> c = {3, 3, 0, 3};
  vector<vector<int>> res = s.permuteUnique(c);
  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto tt = it->begin(); tt != it->end(); tt++) {
      std::cout << *tt << " ";
    }
    std::cout << std::endl;
  }
}

// @lc code=end
