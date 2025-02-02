/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 *
 * https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/description/
 *
 * algorithms
 * Easy (57.61%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    29.8K
 * Total Submissions: 51.8K
 * Testcase Example:  '"01000111"'
 *
 * 给你一个仅由 0 和 1 组成的二进制字符串 s 。  
 *
 * 如果子字符串中 所有的 0 都在 1 之前 且其中 0 的数量等于 1 的数量，则认为 s
 * 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。 
 *
 * 返回  s 中最长的平衡子字符串长度。
 *
 * 子字符串是字符串中的一个连续字符序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "01000111"
 * 输出：6
 * 解释：最长的平衡子字符串是 "000111" ，长度为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "00111"
 * 输出：4
 * 解释：最长的平衡子字符串是 "0011" ，长度为  4 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "111"
 * 输出：0
 * 解释：除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 50
 * '0' <= s[i] <= '1'
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

class Solution {
public:
  int l1 = 0;
  int l2 = 0;
  int max = 0;
  bool revert = false;
  int findTheLongestBalancedSubstring(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0' && !revert) {
        l1++;
      } else if (s[i] == '1' && revert) {
        l2++;
      } else if (s[i] == '0') {
        l1 = 1;
        l2 = 0;
        revert = false;
        max = std::max(max, l1 + l2);
      } else if (s[i] == '1') {
        l2++;
        revert = true;
      }
    }
    return std::max(max, l1 + l2);
  }
};

int main() {
  Solution s;
  int ret = s.findTheLongestBalancedSubstring("01000111");
  cout << "ret: " << ret << endl;
}

// @lc code=end
