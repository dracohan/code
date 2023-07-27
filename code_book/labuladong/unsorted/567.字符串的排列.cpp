/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    936
 * Dislikes: 0
 * Total Accepted:    266.8K
 * Total Submissions: 599.2K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含
 * s1 的排列。如果是，返回 true ；否则，返回 false 。
 *
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 *
 *
 * 示例 2：
 *
 *
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 *
 *
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c : s1) need[c]++;

    int left = 0, right = 0;
    int valid = 0;

    while (right < need.size()) {
      char c = s2[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) valid++;
      }

      while (valid == need.size()) {
        if (right - left == s1.size()) return true;

        char d = s2[left];
        left++;

        if (need.count(d)) {
          if (window[d] == need[d]) valid--;
          window[d]--;
        }
      }
    }

    return false;
  }
};

int main() {
  string s2 = "eidboaooo";
  string s1 = "ab";
  Solution solution;
  bool res = solution.checkInclusion(s1, s2);
  std::cout << "inclusion:" << res << std::endl;
}

// @lc code=end
