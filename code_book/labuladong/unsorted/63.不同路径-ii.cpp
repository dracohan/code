/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (41.11%)
 * Likes:    1137
 * Dislikes: 0
 * Total Accepted:    404.4K
 * Total Submissions: 982.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为
 * “Finish”）。
 *
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 *
 * 示例 2：
 *
 *
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp;
    dp.resize(m);
    for (auto &e : dp)
      e.resize(n);
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < m; i++) {
      dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
      dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
      ;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  vector<vector<int>> coins = {{1,0,0,0,0,0},{0,1,0,1,0,0}};
  Solution s;
  int ret = s.uniquePathsWithObstacles(coins);
  cout << "ret: " << ret << endl;
}
// @lc code=end
