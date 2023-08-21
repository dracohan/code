/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Hard (62.78%)
 * Likes:    3086
 * Dislikes: 0
 * Total Accepted:    390.6K
 * Total Submissions: 621.8K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
 *  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
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
public:
  string path;
  vector<vector<string>> minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<string>> rec(m + 1, vector<string>(n + 1));

    for (int i = 1; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= word2.size(); j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
          rec[i][j] = "ignore";
        } else
          dp[i][j] = std::min(dp[i - 1][j] + 1,
                              std::min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));

        if (dp[i][j] == dp[i - 1][j] + 1)
          rec[i][j] = "delete";
        else if (dp[i][j] == dp[i][j - 1] + 1)
          rec[i][j] = "insert";
        else if (dp[i][j] == dp[i - 1][j - 1] + 1)
          rec[i][j] = "replace";
      }
    }
    // return dp[m][n];
    return rec;
  }
};

int main() {
  string word1 = "horse", word2 = "ros";
  Solution s;
  vector<vector<string>> ret = s.minDistance(word1, word2);
  //   cout << "ret: " << ret << endl;
  for (auto &x : ret)
    for (auto &y : x)
      cout << y << " " << endl;
  cout << std::endl;
}

// @lc code=end
