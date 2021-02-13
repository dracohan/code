// 当 A?的子数组?A[i], A[i+1], ..., A[j]?满足下列条件时，我们称其为湍流子数组：

// 若?i <= k < j，当 k?为奇数时，?A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
// 或 若?i <= k < j，当 k 为偶数时，A[k] > A[k+1]?，且当 k?为奇数时，?A[k] < A[k+1]。
// 也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

// 返回 A 的最大湍流子数组的长度。


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