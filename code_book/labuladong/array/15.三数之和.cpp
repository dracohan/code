/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (37.21%)
 * Likes:    6236
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 * 
 * 你返回所有和为 0 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_set>

#include "../utils/utils.h"

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res = nSum(nums, 0, 3, 0);
        return res;
    }

    vector<vector<int>> nSum(vector<int> & nums, int start, int n, int target) {
        vector<vector<int>> res;
        int sz = nums.size(); 
        if (n < 2 || sz < n) return res;

        if (n == 2) {
            int lo = start;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo];
                int right = nums[hi];
                if (sum < target) {
                    while(lo < hi && nums[lo] == left) lo++;
                } else if (sum > target) {
                    while(lo < hi && nums[hi] == right) hi--;
                } else {
                    res.push_back({left, right});
                    // ignore duplicate
                    while(lo < hi && nums[lo] == left) lo++;
                    while(lo < hi && nums[hi] == right) hi--;
                }
            }
        } else {
            for (int i = start; i < sz; i++) {
                vector<vector<int>> sub = nSum(nums, i + 1, n - 1, target - nums[i]);
                for (vector<int>& arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                // 跳过第一个数字重复的情况，否则会出现重复结果
                while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
            }
        }
        return res;
    }
};

int main() {
  vector<int> nums = {-1,0,1,2,-1,-4};
  Solution s;
  vector<vector<int>> ret = s.threeSum(nums);
  for (auto &r : ret)
    printCollection(r);
}

// @lc code=end

