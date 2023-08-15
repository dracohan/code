/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.17%)
 * Likes:    1845
 * Dislikes: 0
 * Total Accepted:    438.9K
 * Total Submissions: 841.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start


#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sz = nums.size();
    if (sz < 2)
      return false;

    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum % 2 != 0)
      return false;

    int target = sum / 2;

    //对于前 i 个物品（i 从 1 开始计数），当前背包的容量为 j 时的答案
    vector<vector<bool>> dp(sz + 1, vector<bool>(target + 1));

    for (int i = 0; i < sz; i++)
      dp[i][0] = true;

    for (int j = 0; j < target; j++)
      dp[0][j] = false;

    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= target; j++)
        if (j - nums[i - 1] < 0)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    }
    return dp[sz][target];
  }
};

int main() {
  vector<int> coins = {1,5,11,5};
  Solution s;
  bool ret = s.canPartition(coins);
  std::cout << "ret: " << (bool)ret << std::endl;
}

// @lc code=end
