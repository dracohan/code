#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
