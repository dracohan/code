/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 *
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (68.05%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    84.6K
 * Total Submissions: 124.6K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径
 * 的 最小和 。
 *
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row +
 * 1, col + 1) 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：如图所示，为和最小的两条下降路径
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：如图所示，为和最小的下降路径
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<long>> dp(m + 1, vector<long>(n + 2, 66666));

    for (int k = 0; k < n + 2; k++)
      dp[m][k] = 0;

    for (int i = m - 1; i >= 0; i--) {
      for (int j = 1; j < n + 1; j++) {
        dp[i][j] = std::min(std::min(dp[i + 1][j - 1], dp[i + 1][j]),
                            dp[i + 1][j + 1]) +
                   matrix[i][j - 1];
      }
    }

    long res = 66666;
    for (int i = 1; i < n + 1; i++)
      res = std::min(res, dp[0][i]);
    return res;
  }
};
// @lc code=end
