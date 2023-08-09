/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (54.83%)
 * Likes:    6202
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums
 * ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    // 定义：dp[i] 记录以 nums[i] 为结尾的「最大子数组和」
    vector<int> dp(n);
    // base case
    // 第一个元素前面没有子数组
    dp[0] = nums[0];
    // 状态转移方程
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }
    // 得到 nums 的最大子数组
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
      res = max(res, dp[i]);
    }
    return res;
  }
  int maxSubArray_2(vector<int> &nums) {
    int left = 0, right = 0;
    int windowSum = 0, maxSum = INT_MIN;
    while (right < nums.size()) {
      // 扩大窗口并更新窗口内的元素和
      windowSum += nums[right];
      right++;

      // 更新答案
      maxSum = windowSum > maxSum ? windowSum : maxSum;

      // 判断窗口是否要收缩
      while (windowSum < 0) {
        // 缩小窗口并更新窗口内的元素和
        windowSum -= nums[left];
        left++;
      }
    }
    return maxSum;
  }
};
// @lc code=end
