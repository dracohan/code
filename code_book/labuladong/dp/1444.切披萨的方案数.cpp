/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] 切披萨的方案数
 *
 * https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/description/
 *
 * algorithms
 * Hard (54.32%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 20K
 * Testcase Example:  '["A..","AAA","..."]\n3'
 *
 * 给你一个 rows x cols 大小的矩形披萨和一个整数 k ，矩形包含两种字符： 'A'
 * （表示苹果）和 '.' （表示空白格子）。你需要切披萨 k-1
 * 次，得到 k 块披萨并送给别人。
 *
 *
 * 切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。
 *
 * 请你返回确保每一块披萨包含 至少 一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对
 * 10^9 + 7 取余的结果。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：pizza = ["A..","AAA","..."], k = 3
 * 输出：3
 * 解释：上图展示了三种切披萨的方案。注意每一块披萨都至少包含一个苹果。
 *
 *
 * 示例 2：
 *
 * 输入：pizza = ["A..","AA.","..."], k = 3
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：pizza = ["A..","A..","..."], k = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rows, cols <= 50
 * rows == pizza.length
 * cols == pizza[i].length
 * 1 <= k <= 10
 * pizza 只包含字符 'A' 和 '.' 。
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
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
  int ways(vector<string> &pizza, int k) {
    int m = pizza.size(), n = pizza[0].size(), mod = 1e9 + 7;
    vector<vector<int>> apples(m + 1, vector<int>(n + 1));
    //dp[k][i][j]\textit{dp}[k][i][j]dp[k][i][j] 表示把坐标 (i,j)(i, j)(i,j) 右下方的披萨切割成 kkk 块披萨的方案数量
    vector<vector<vector<int>>> dp(
        k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

    // 预处理
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        apples[i][j] = apples[i][j + 1] + apples[i + 1][j] -
                       apples[i + 1][j + 1] + (pizza[i][j] == 'A');
        dp[1][i][j] = apples[i][j] > 0;
      }
    }

    for (int ki = 2; ki <= k; ki++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          // 水平方向切
          for (int i2 = i + 1; i2 < m; i2++) {
            if (apples[i][j] > apples[i2][j]) {
              dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
            }
          }
          // 垂直方向切
          for (int j2 = j + 1; j2 < n; j2++) {
            if (apples[i][j] > apples[i][j2]) {
              dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
            }
          }
        }
      }
    }
    return dp[k][0][0];
  }
};

int main() {
  vector<string> pizza = {"A..","AAA","..."};
  Solution s;
  int ret = s.ways(pizza, 3);
  std::cout << "ret:" << ret << std::endl;
}


// @lc code=end
