#include <vector>
#include <iostream>

using namespace std;

int fib(int N) {
    if (N < 1) return 0;
    if (N == 1 || N == 2) return 1;
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}

int main() {
    cout << "fib(20): " << fib(20) << endl;
}