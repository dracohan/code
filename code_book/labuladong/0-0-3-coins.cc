#include <iostream>
#include <map>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;

  int res = amount + 1;
  for (int i = 0; i < coins.size(); i++) {
    int sub = coinChange(coins, amount - coins[i]);
    if (sub == -1) continue;  // not found
    if (res > sub + 1) res = sub + 1;
  }

  if (res > 0 && res < amount + 1)
    return res;
  else
    return -1;
}

map<int, int> memo;
int coinChange_with_memo(vector<int> &coins, int amount) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;

  if ((memo[amount]) != 0) return memo[amount];

  int res = amount + 1;
  for (int i = 0; i < coins.size(); i++) {
    int sub = coinChange_with_memo(coins, amount - coins[i]);

    if (sub == -1) continue;
    if (res > sub + 1) res = sub + 1;

    memo[amount - coins[i]] = sub;
  }

  // if (amount == 11) // final
  //   cout << "break" << endl;

  if (res > 0 && res < amount + 1)
    return res;
  else
    return -1;
}

vector<int> count;
int dp(vector<int> &coins, int amount) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;

  if ((count[amount]) != 0) return count[amount];

  int res = amount + 1;
  for (int i = 0; i < coins.size(); i++) {
    int sub = dp(coins, amount - coins[i]);

    if (sub == -1) continue;
    if (res > sub + 1) res = sub + 1;
  }

  // if (amount == 11) 
  //   cout << "break" << endl;
  if (res == amount + 1)
    count[amount] = -1;
  else
    count[amount] = res;

  if (res > 0 && res < amount + 1) {
    return res;
  }

  return -1;
}

// int dp(vector<int> &coins, int rem) {
//   if (rem < 0) return -1;
//   if (rem == 0) return 0;
//   if (count[rem - 1] != 0) return count[rem - 1];
//   cout << "calc: " << rem << endl;
//   int Min = 65536;
//   for (int coin : coins) {
//     int res = dp(coins, rem - coin);
//     if (res >= 0 && res < Min) {
//       Min = res + 1;
//     }
//   }
//   count[rem - 1] = Min == 65536 ? -1 : Min;
//   return count[rem - 1];
// }

int coinChange_with_vec(vector<int> &coins, int amount) {
  if (amount < 1) return 0;
  count.resize(amount + 1);
  return dp(coins, amount);
}

int main() {
  // vector<int> coins = {186, 419, 83, 408};
  // int ret = coinChange_with_vec(coins, 6249);
  vector<int> coins = {1, 2, 5};
  int ret = coinChange_with_vec(coins, 11);
  cout << "ret: " << ret << endl;
}
