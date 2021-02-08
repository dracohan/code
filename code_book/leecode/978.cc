#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static void toggle(bool& flag) {
    if (flag)
      flag = false;
    else
      flag = true;
  }
  static int maxTurbulenceSize(vector<int>& arr) {
    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
      bool flag = false;
      int cnt = 1;
      for (int k = i; k < arr.size() - 1; k++) {
        if (k % 2 == 0) {
          if (flag) {
            if (arr[k] < arr[k + 1]) {
              toggle(flag);
              cnt++;
              continue;
            } else {
              break;
            }
          } else {
            if (arr[k] > arr[k + 1]) {
              toggle(flag);
              cnt++;
              continue;
            } else {
              break;
            }
          }
        } else {
          if (flag) {
            if (arr[k] > arr[k + 1]) {
              toggle(flag);
              cnt++;
              continue;
            } else {
              break;
            }
          } else {
            if (arr[k] < arr[k + 1]) {
              toggle(flag);
              cnt++;
              continue;
            } else {
              break;
            }
          }
        }
      }
      if (cnt > max) max = cnt;
    }
    return max;
  }
};

int main() {
  // std::vector<int> a = {9, 4, 2, 10, 7, 8, 8, 1, 9};
  // std::vector<int> a = {4,8,12,16};
  // std::vector<int> a = {100};
  std::vector<int> a = {9, 4, 2, 10, 7, 8, 8, 1, 9};

  int m = Solution::maxTurbulenceSize(a);
  std::cout << m << std::endl;
}