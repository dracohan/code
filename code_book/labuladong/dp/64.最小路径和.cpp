/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    1542
 * Dislikes: 0
 * Total Accepted:    500.3K
 * Total Submissions: 719.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid
 * ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
  vector<vector<int>> memo;
  int indent = 0;

 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
     memo = vector<vector<int>>(m, vector<int>(n, -1));
    return dp(grid, m - 1, n - 1);
  }

  int dp(vector<vector<int>>& grid, int i, int j) {
    printIndent(indent++);
    printf("dp i: %d j: %d\n", i, j);

    if (i == 0 && j == 0) {
      printIndent(indent--);
      printf("getting grid[0][0]\n");
      return grid[0][0];
    }

    if (i < 0 || j < 0) {
      printIndent(indent--);
      printf("invalid path\n");
      return INT_MAX;
    }

    if (memo[i][j] != -1) {
      printIndent(indent--);
      printf("retrieve memo[%d][%d]\n", i, j);
      return memo[i][j];
    }

    memo[i][j] = min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];
    printIndent(indent--);
    printf("returning memo[%d][%d]\n", i, j);
    return memo[i][j];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution s;
  int ret = s.minPathSum(grid);
  cout << "ret: " << ret << endl;
}
// @lc code=end
