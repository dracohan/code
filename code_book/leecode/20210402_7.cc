// 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

// 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
// 假设环境不允许存储 64 位整数（有符号或无符号）。

 

// 示例 1：

// 输入：x = 123
// 输出：321

// 示例 2：

// 输入：x = -123
// 输出：-321

// 示例 3：

// 输入：x = 120
// 输出：21

// 示例 4：

// 输入：x = 0
// 输出：0

 

// 提示：

//     -231 <= x <= 231 - 1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-integer
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <string>
using namespace std;

class Solution {
private: 
  bool neg = false;
public:
    int reverse(int x) {
      if (x < 0) neg = true;
      std::string s = std::to_string(x);
      for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        const char c = s[i];
        s[i] = s[j];
        s[j] = c;
      }
      // std::cout << s << std::endl;
      int mark=0;
      for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') mark = i;
        else break;
      }
      if (mark !=0 ) s = s.substr(mark);
      int n = 0;
      try {

      n = std::stoi(s);
      } catch(exception& e) {
        return 0;
      }
      if (neg) n = 0 - n;
      // if ( n < -2147483648 || n > 2147483648) return 0;
      return n;
    }
};


int main() {
  Solution s;
  int t = s.reverse(901000);
  std::cout << t << std::endl;

}