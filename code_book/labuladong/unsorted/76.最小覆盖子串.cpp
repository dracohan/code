/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.15%)
 * Likes:    2583
 * Dislikes: 0
 * Total Accepted:    441.5K
 * Total Submissions: 976.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    // need每个字符需要几个
    // window每个字符现在有几个
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; /*需要的字符被满足的个数*/
    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) valid++;
      }

      while (valid == need.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }

        char d = s[left];
        left++;

        if (need.count(d)) {
          if (window[d] == need[d]) valid--;
          window[d]--;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  Solution solution;
  string res = solution.minWindow(s, t);
  std::cout << "min string:" << res << std::endl;
}

// @lc code=end
