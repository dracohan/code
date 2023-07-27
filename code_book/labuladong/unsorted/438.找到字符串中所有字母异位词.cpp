/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.87%)
 * Likes:    1229
 * Dislikes: 0
 * Total Accepted:    302.6K
 * Total Submissions: 553.9K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和
 * p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    vector<int> res;

    for (char c : p) need[c]++;

    int right = 0, left = 0;
    int valid = 0;

    while (right < s.size()) {
      char c = s[right];
      //   window[c]++;
      right++;

      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) valid++;
      }

      while (valid == need.size()) {
        if (right - left == p.size()) res.push_back(left);

        //   while (right - left >= p.size()) {
        //     // 当窗口符合条件时，把起始索引加入 res
        //     if (valid == need.size()) res.push_back(left);

        char d = s[left];
        left++;

        if (need.count(d)) {
          if (need[d] == window[d]) valid--;
          window[d]--;
        }
      }
    }
    return res;
  }
};

int main() {
  string s = "baa";
  string p = "aa";
  Solution solution;
  vector<int> res = solution.findAnagrams(s, p);
  printCollection(res, "|");
}

// @lc code=end
