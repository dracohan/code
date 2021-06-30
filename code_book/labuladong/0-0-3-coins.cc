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

vector<int> count;
int dp(vector<int> &coins, int amount) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;

  if ((count[amount]) != -2) return count[amount];

  int res = amount + 1;
  for (int i = 0; i < coins.size(); i++) {
    int sub = dp(coins, amount - coins[i]);
    if (sub == -1) continue;
    if (res > sub + 1) res = sub + 1;
  }

  if (res == amount + 1)
    count[amount] = -1;
  else
    count[amount] = res;

  return count[amount];
}

// int dp(vector<int> &coins, int rem) {
//   if (rem < 0) return -1;
//   if (rem == 0) return 0;
//   if (count[rem - 1] != -2) return count[rem - 1];
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

int coinChange_memo(vector<int> &coins, int amount) {
  if (amount < 1) return 0;
  count.assign(amount + 1, -2);
  return dp(coins, amount);
}

int main() {
  vector<int> coins = {1, 2, 5};
  int ret = coinChange_memo(coins, 11);
  cout << "ret: " << ret << endl;
}
