/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.07%)
 * Likes:    1845
 * Dislikes: 0
 * Total Accepted:    321.6K
 * Total Submissions: 434.3K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
    #include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
bool isValid(vector<string> board, int row, int col) {
  for (int j = 0; j < board.size(); j++) {
    if (board[j][col] == 'Q') return false;
  }

  // if (board[row - 1][col - 1] == 'Q') return false;
  // if (board[row - 1][col + 1] == 'Q') return false;
  // if (board[row + 1][col - 1] == 'Q') return false;
  // if (board[row + 1][col + 1] == 'Q') return false;
  int i = row - 1;
  int j = col + 1;
  for (; i >= 0 && j < board.size(); i--, j++) {
    if (board[i][j] == 'Q') return false;
  }

  i = row - 1, j = col - 1;
  for (; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') return false;
  }

  return true;
}

void backtrace(vector<string> board, int row, vector<vector<string>>& res) {
  if (row == board.size()) {
    res.push_back(board);
    return;
  }

  int n = board[row].size();
  for (int col = 0; col < n; col++) {
    if (!isValid(board, row, col)) continue;

    board[row][col] = 'Q';
    backtrace(board, row + 1, res);
    board[row][col] = '.';
  }
}

vector<vector<string>> solveNQueen(int n) {
  vector<vector<string>> res;
  vector<string> board(n, string(n, '.'));
  backtrace(board, 0, res);
  return res;
}

int main() {
  vector<vector<string>> res = solveNQueen(5);
  for (auto it = res.begin(); it != res.end(); it++){
    for (auto tt = it->begin(); tt != it->end(); tt++){
      std::cout << *tt << " " << std::endl;
    }
    std::cout << std::endl;
  }
}

};
// @lc code=end

