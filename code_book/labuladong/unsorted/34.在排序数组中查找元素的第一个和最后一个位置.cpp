/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.35%)
 * Likes:    2393
 * Dislikes: 0
 * Total Accepted:    819.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
 * target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <vector>
#include "../utils/utils.h"
using namespace std;
class Solution {
 public:
  int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] == target) {
        // 别返回，锁定左侧边界
        right = mid - 1;
      }
    }
    // 判断 target 是否存在于 nums 中
    if (left < 0 || left >= nums.size()) {
      return -1;
    }
    // 判断一下 nums[left] 是不是 target
    return nums[left] == target ? left : -1;
  }

  int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] == target) {
        // 别返回，锁定右侧边界
        left = mid + 1;
      }
    }
    // 判断 target 是否存在于 nums 中
    // if (left - 1 < 0 || left - 1 >= nums.size()) {
    //     return -1;
    // }

    // 由于 while 的结束条件是 right == left - 1，且现在在求右边界
    // 所以用 right 替代 left - 1 更好记
    if (right < 0 || right >= nums.size()) {
      return -1;
    }
    return nums[right] == target ? right : -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int left = left_bound(nums, target);
    int right = right_bound(nums, target);
    return {left, right};
  }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    Solution s;
    vector<int> range = s.searchRange(nums, 8);
    printCollection(range);

}
// @lc code=end
