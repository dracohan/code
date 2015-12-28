// 3.cc
#include <iostream>
using namespace std;

// 求子数组连续最大和
int max_sub_sum(int* a, int n) {
      int sum = a[0];
      int start = a[0];
      for(int i = 1; i <= n-1; i++) {
            start = max(start + a[i], a[i]);
            sum = max(sum, start);
      }
      return sum;
}

int main() {
      int a[7] = {1, -2, 3, 10, -4, 7, 2, -5};
      int max_sub = max_sub_sum(a, 8);
      cout << "max sub sum is: " << max_sub << endl;
}