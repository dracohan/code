// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121
// 是回文，而 123 不是。

// 示例 1：

// 输入：x = 121
// 输出：true

// 示例 2：

// 输入：x = -121
// 输出：false
// 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

// 示例 3：

// 输入：x = 10
// 输出：false
// 解释：从右向左读, 为 01 。因此它不是一个回文数。

// 示例 4：

// 输入：x = -101
// 输出：false
#include <iostream>
#include <string>

//using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    std::string s = std::to_string(x);
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      const char c1 = s[i];
      const char c2 = s[j];
      if (c1 != c2) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  // std::cout << s.isPalindrome(121) << std::endl;
  // std::cout << s.isPalindrome(1000021) << std::endl;
  return 0;
}
