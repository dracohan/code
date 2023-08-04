/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode.cn/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (64.88%)
 * Likes:    1377
 * Dislikes: 0
 * Total Accepted:    355.6K
 * Total Submissions: 548K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 
 * 
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 
 * 
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * text1 和 text2 仅由小写英文字符组成。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  // 备忘录，消除重叠子问题
  vector<vector<int>> memo;

  /* 主函数 */
  int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    // 备忘录值为 -1 代表未曾计算
    memo.resize(m, vector<int>(n, -1));
    // 计算 s1[0..] 和 s2[0..] 的 lcs 长度
    return dp(s1, 0, s2, 0);
  }

  // 定义：计算 s1[i..] 和 s2[j..] 的最长公共子序列长度
  int dp(string s1, int i, string s2, int j) {
    // base case
    if (i == s1.size() || j == s2.size()) {
      return 0;
    }
    // 如果之前计算过，则直接返回备忘录中的答案
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    // 根据 s1[i] 和 s2[j] 的情况做选择
    if (s1[i] == s2[j]) {
      // s1[i] 和 s2[j] 必然在 lcs 中
      memo[i][j] = 1 + dp(s1, i + 1, s2, j + 1);
    } else {
      // s1[i] 和 s2[j] 至少有一个不在 lcs 中
      memo[i][j] = max(dp(s1, i + 1, s2, j), dp(s1, i, s2, j + 1));
    }
    return memo[i][j];
  }
};
// @lc code=end

