// 给定一个范围在? 1 ≤ a[i] ≤ n (?n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。

// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

// 示例:

// 输入:
// [4,3,2,7,8,2,3,1]

// 输出:
// [5,6]


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> findDisappearedNumbers(vector<int> &nums) {
    int len = nums.size();
    int exp = 1;
    vector<int> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++) {
      if (nums[i] == exp) {
        exp++;
      } else if (nums[i] < exp) {
        continue;
      } else if (nums[i] > exp) {
        for (int j = exp; j < nums[i]; j++) {
          res.push_back(j);
        }
        exp = nums[i] + 1;
      }
    }
    for (int k = exp; k <= len; k++) res.push_back(k);
    return res;
  }
};

int main() {
  // vector<int> test = {4,3,2,7,8,2,3,1};
  vector<int> test = {1, 1};
  vector<int> res = Solution::findDisappearedNumbers(test);
  // for (auto a : res)
  //   std::cout << a << std::endl;
}