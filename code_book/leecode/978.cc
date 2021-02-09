#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static int largeAtEven(vector<int>& arr, int n) {
    int cnt = 1;
    for (int i = n; i < arr.size() - 1; i++) {
      if (i % 2 == 0) {
        if (arr[i] > arr[i + 1])
          cnt++;
        else
          break;
      } else {
        if (arr[i] < arr[i + 1])
          cnt++;
        else
          break;
      }
    }
    return cnt;
  }

  static int largeAtOdd(vector<int>& arr, int n) {
    int cnt = 1;
    for (int i = n; i < arr.size() - 1; i++) {
      if (i % 2 != 0) {
        if (arr[i] > arr[i + 1])
          cnt++;
        else
          break;
      } else {
        if (arr[i] < arr[i + 1])
          cnt++;
        else
          break;
      }
    }
    return cnt;
  }

  static int lessAtEven(vector<int>& arr, int n) {
    int cnt = 1;
    for (int i = n; i < arr.size() - 1; i++) {
      if (i % 2 == 0) {
        if (arr[i] < arr[i + 1])
          cnt++;
        else
          break;
      } else {
        if (arr[i] > arr[i + 1])
          cnt++;
        else
          break;
      }
    }
    return cnt;
  }

  static int lessAtOdd(vector<int>& arr, int n) {
    int cnt = 1;
    for (int i = n; i < arr.size() - 1; i++) {
      if (i % 2 != 0) {
        if (arr[i] < arr[i + 1])
          cnt++;
        else
          break;
      } else {
        if (arr[i] > arr[i + 1])
          cnt++;
        else
          break;
      }
    }
    return cnt;
  }

  static int maxTurbulenceSize(vector<int>& arr) {
    int max = 1;
    int cnt = 1;
    for (int i = 0; i < arr.size() - 1;) {
      cnt = 1;
      if (arr[i] > arr[i + 1]) {
        if (i % 2 == 0) {
          cnt = largeAtEven(arr, i);
        } else {
          cnt = largeAtOdd(arr, i);
        }
      } else {
        if (i % 2 == 0) {
          cnt = lessAtEven(arr, i);
        } else {
          cnt = lessAtOdd(arr, i);
        }
      }

      if (cnt > max) max = cnt;
      if (cnt > 1)
        i = i + cnt - 1;
      else
        i = i + 1;
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