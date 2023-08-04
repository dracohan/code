/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.36%)
 * Likes:    2492
 * Dislikes: 0
 * Total Accepted:    652.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount
 * ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数
 * 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/utils.h"

using namespace std;

// int coinChange(vector<int> &coins, int amount) {
//   if (amount == 0) return 0;
//   if (amount < 0) return -1;

//   int res = amount + 1;
//   for (int i = 0; i < coins.size(); i++) {
//     int sub = coinChange(coins, amount - coins[i]);
//     if (sub == -1) continue;  // not found
//     if (res > sub + 1) res = sub + 1;
//   }

//   if (res > 0 && res < amount + 1)
//     return res;
//   else
//     return -1;
// }

vector<int> memo;
int indent = 0;
int dp(vector<int> &coins, int amount) {
  printIndent(indent++);
  printf("amount: %d\n", amount);
  if (amount == 0) {
    printIndent(indent--);
    printf("return 0\n");
    return 0;
  }
  if (amount < 0) {
    printIndent(indent--);
    printf("return -1\n");
    return -1;
  }

  if ((memo[amount]) != -2) {
    printIndent(indent--);
    printf("return memo[%d]\n", amount);
    return memo[amount];
  }

  int res = amount + 1;  //+1 means inifity for ammount
  for (int i = 0; i < coins.size(); i++) {
    int sub = dp(coins, amount - coins[i]);
    if (sub == -1) continue;
    res = std::min(res, sub + 1);
  }

  memo[amount] = (res == amount + 1) ? -1 : res;

  printIndent(indent--);
  printf("return memo[%d]\n", amount);
  return memo[amount];
}

// int dp(vector<int> &coins, int rem) {
//   if (rem < 0) return -1;
//   if (rem == 0) return 0;
//   if (memo[rem - 1] != -2) return memo[rem - 1];
//   cout << "calc: " << rem << endl;
//   int Min = 65536;
//   for (int coin : coins) {
//     int res = dp(coins, rem - coin);
//     if (res >= 0 && res < Min) {
//       Min = res + 1;
//     }
//   }
//   memo[rem - 1] = Min == 65536 ? -1 : Min;
//   return memo[rem - 1];
// }

int coinChange_memo(vector<int> &coins, int amount) {
  if (amount < 1) return 0;
  memo.assign(amount + 1, -2);
  return dp(coins, amount);
}

int main() {
  vector<int> coins = {1, 2, 5};
  int ret = coinChange_memo(coins, 11);
  cout << "ret: " << ret << endl;
}
