/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (63.77%)
 * Likes:    2214
 * Dislikes: 0
 * Total Accepted:    881.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // 小顶堆，堆顶是最小元素
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int e : nums) {
        pq.push(e);
        if (pq.size() > k) {
          pq.pop();
        }
        }
        return pq.top();
    }
};

int main() {
  vector<int> nums = {3,2,1,5,6,4};
  Solution solution;
  int res = solution.findKthLargest(nums, 2);
  std::cout << "kth largest:" << res << std::endl;
}


// @lc code=end

