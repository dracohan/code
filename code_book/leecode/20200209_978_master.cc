#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  static int maxTurbulenceSize(vector<int>& arr) {
    int len = arr.size();
    if (len < 2) return len;
    int increased[len];
    int decreased[len];
    increased[0] = 1;
    decreased[0] = 1;
    int max = 1;
    for (int i = 1; i < len; i++) {
      if (arr[i - 1] < arr[i]) {
        increased[i] = decreased[i - 1] + 1;
        decreased[i] = 1;
      } else if (arr[i - 1] > arr[i]) {
        decreased[i] = increased[i - 1] + 1;
        increased[i] = 1;
      } else {
        increased[i] = 1;
        decreased[i] = 1;
      }
      max = std::max(max, std::max(increased[i], decreased[i]));
    }
    return max;
  }
};

int main() {
  std::vector<int> a = {9, 4, 2, 10, 7, 8, 8, 1, 9};
  // std::vector<int> a = {4, 8, 12, 16};
  // std::vector<int> a = {100};
  // std::vector<int> a = {9, 4, 2, 10, 7, 8, 8, 1, 9};

  int m = Solution::maxTurbulenceSize(a);
  std::cout << m << std::endl;
}