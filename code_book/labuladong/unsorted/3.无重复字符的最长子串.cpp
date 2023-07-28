/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.09%)
 * Likes:    9405
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 6.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>

#include "../utils/utils.h"

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring_own(string s) {
    int right = 1, left = 0;
    int longest = 0;

    if (s.size() <= 1) return s.size();

    while (right < s.size()) {
      char c = s[right];

      while (left < right) {
        string sub = s.substr(left, right - left);
        if (sub.find(c) == std::string::npos) break;
        left++;
      }
      if (right - left + 1 > longest) longest = right - left + 1;
      right++;
    }
    return longest;
  }

  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    int right = 0, left = 0;
    int longest = 0;

    while (right < s.size()) {
      char c = s[right];
      right++;

      window[c]++;

      while (window[c] > 1) {
        char d = s[left];
        left++;
        window[d]--;
      }
      longest = max(longest, right - left);
    }
    return longest;
  }
};

int main() {
  string s = "pwwkew";
  Solution solution;
  int res = solution.lengthOfLongestSubstring(s);
  std::cout << "longest substring:" << res << std::endl;
}

// @lc code=end
