/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.88%)
 * Likes:    1717
 * Dislikes: 0
 * Total Accepted:    494.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
 * 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c],
 * nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res = nSum(nums, 0, 4, target);
    return res;
  }

  vector<vector<int>> nSum(vector<int> &nums, int start, int n, long target) {
    vector<vector<int>> res;
    int sz = nums.size();
    if (n < 2 || sz < n)
      return res;

    if (n == 2) {
      int lo = start;
      int hi = sz - 1;
      while (lo < hi) {
        long sum = nums[lo] + nums[hi];
        int left = nums[lo];
        int right = nums[hi];
        if (sum < target) {
          while (lo < hi && nums[lo] == left)
            lo++;
        } else if (sum > target) {
          while (lo < hi && nums[hi] == right)
            hi--;
        } else {
          res.push_back({left, right});
          while (lo < hi && nums[lo] == left)
            lo++;
          while (lo < hi && nums[hi] == right)
            hi--;
        }
      }
    } else {
      for (int i = start; i < sz; i++) {
        vector<vector<int>> sub = nSum(nums, i + 1, n - 1, target - nums[i]);
        for (vector<int> &arr : sub) {
          arr.push_back(nums[i]);
          res.push_back(arr);
        }
        while (i < sz - 1 && nums[i] == nums[i + 1])
          i++;
      }
    }
    return res;
  }

  vector<vector<int>> fourSum_dbg(vector<int> &nums, int target) {
    // std::sort(nums.begin(), nums.end());
    vector<vector<int>> res = coinChange(nums, 0, target);
    return res;
  }

  vector<vector<int>> coinChange(vector<int> &coins, int start, int amount) {
    // base case
    vector<vector<int>> res;
    vector<int> arr;

    if (amount == 0 && !arr.empty()) {
        return {{0}};
    }
    if (amount == -1 && !arr.empty()) {
        return {{-1}};
    }
    // int res = INT_MAX;
    for (int i = start; i < coins.size(); i++) {
      // 递归计算凑出 amount - coin 的最少硬币个数
      arr.push_back(coins[i]);

      vector<vector<int>> subProblem = coinChange(coins, start + 1, amount + coins[i]);
      if (!subProblem.empty() && subProblem[0][0] == -1)
        continue;
      if (!subProblem.empty() && subProblem[0][0] == 0) {
        arr.push_back(coins[i]);
        res.push_back(arr);
      }
      arr.pop_back();
    }

    return res;
  }
};

int main() {
  vector<int> nums = {1, 2, 1, -1, -2};
  Solution s;
  vector<vector<int>> ret = s.fourSum_dbg(nums, 0);
  for (auto &r : ret)
    printCollection(r);
}

// @lc code=end
