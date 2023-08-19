/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (52.26%)
 * Likes:    1101
 * Dislikes: 0
 * Total Accepted:    147.3K
 * Total Submissions: 282.2K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
 *
 * 题目数据保证答案符合 32 位带符号整数范围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 *
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
  // 用哈希集合方便快速判断是否存在
  unordered_set<string> wordDict;
  // 备忘录，-1 代表未计算，0 代表无法凑出，1 代表可以凑出
  vector<int> memo;

 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // 转化为哈希集合，快速判断元素是否存在
    for (auto word : wordDict) {
      this->wordDict.insert(word);
    }
    // 备忘录初始化为 -1
    memo.resize(s.length(), -1);
    return dp(s, 0);
  }

  // 定义：s[i..] 是否能够被拼出
  bool dp(const string& s, int i) {
    // base case
    if (i == s.length()) {
      return true;
    }
    // 防止冗余计算
    if (memo[i] != -1) {
      return memo[i] == 0 ? false : true;
    }

    // 遍历 s[i..] 的所有前缀
    for (int len = 1; i + len <= s.length(); len++) {
      // 看看哪些前缀存在 wordDict 中
      string prefix = s.substr(i, len);
      if (wordDict.count(prefix)) {
        // 找到一个单词匹配 s[i..i+len)
        // 只要 s[i+len..] 可以被拼出，s[i..] 就能被拼出
        bool subProblem = dp(s, i + len);
        if (subProblem == true) {
          memo[i] = 1;
          return true;
        }
      }
    }
    // s[i..] 无法被拼出
    memo[i] = 0;
    return false;
  }
};
// @lc code=end
