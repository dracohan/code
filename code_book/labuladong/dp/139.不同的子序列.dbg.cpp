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
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
  unordered_set<string> wds;
  bool res = false;
  unordered_map<int, bool> memo;

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    for (auto &s : wordDict)
      wds.insert(s);
    dp(s, 0);
    return res;
  }

  void dp(string s, int start) {
    if (res == true)
      return;

    if (memo.contains(start) && memo[start] == false)
      return;

    if (start == s.size()) {
      res = true;
      return;
    }
    for (auto &wd : wds) {
      int len = wd.size();
      if (start + len > s.size()) {
        continue;
      }
      if (wd == s.substr(start, len)) {
        dp(s, start + len);
        if (res == true)
          return;
      }
    }

    res = false;
    memo[start] == false;
  }
};

int main() {
  string str = "bb";
  vector<string> wordDict = {"a", "b", "bbb", "bbbb"};
  Solution s;
  int ret = s.wordBreak(str, wordDict);
  cout << "ret: " << ret << endl;
}

// @lc code=end
