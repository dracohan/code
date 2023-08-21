/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.60%)
 * Likes:    1698
 * Dislikes: 0
 * Total Accepted:    367.2K
 * Total Submissions: 755.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 *
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式
 * ：
 *
 *
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
 * ，然后串联起来得到表达式 "+2-1" 。
 *
 *
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
public:
public:
  int count = 0;
  vector<string> track;
  vector<vector<string>> pathes;
  
  int findTargetSumWays(vector<int> &nums, int target) {
    backtrack(nums, target, 0, 0);
    return count;
  }

  void backtrack(vector<int> &nums, int target, int index, int sum) {
    if (index == nums.size()) {
      if (sum == target) {
        pathes.push_back(track);
        count++;
      }
    } else {
      track.push_back("+" + std::to_string(nums[index]));
      backtrack(nums, target, index + 1, sum + nums[index]);
      track.pop_back();

      track.push_back("-" + std::to_string(nums[index]));
      backtrack(nums, target, index + 1, sum - nums[index]);
      track.pop_back();
    }
  }
};

int main() {
  vector<int> coins = {1, 1, 1, 1, 1};
  Solution s;
  int ret = s.findTargetSumWays(coins, 3);
  for (const auto & path : s.pathes) {
    printCollection(path);
  }
}
// @lc code=end
