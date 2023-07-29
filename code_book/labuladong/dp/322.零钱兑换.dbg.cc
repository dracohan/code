/*
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)
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
