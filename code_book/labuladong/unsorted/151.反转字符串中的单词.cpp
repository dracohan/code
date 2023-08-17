/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (51.92%)
 * Likes:    962
 * Dislikes: 0
 * Total Accepted:    426.9K
 * Total Submissions: 818.5K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词
 * 分隔开。
 *
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 *
 * 注意：输入字符串
 * s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 *
 *
 *
 *
 *
 *
 *
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1)
 * 额外空间复杂度的 原地 解法。
 *
 */

// @lc code=start

#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (s[i] == ' ')
      i++;
    while (s[j] == ' ')
      j--;

    s = s.substr(i, j - i + 1);
    int sz = j - i + 1;

    for (int i = 0, j = sz - 1; i < j; i++, j--) {
      std::swap(s[i], s[j]);
    }

    stack<char> st;
    char *res = new char[sz + 1];
    int k = 0;
    for (int i = 0; i < sz; i++) {
      if (s[i] != ' ') {
        st.push(s[i]);
      } else if (!st.empty()) {
        while (!st.empty()) {
          res[k++] = st.top();
          st.pop();
        }
        res[k++] = ' ';
      }
    }

    while (!st.empty()) {
      res[k++] = st.top();
      st.pop();
    }
    res[k++] = '\0';
    
    return (string)res;
  }
};

// using namespace std;
// // reverse the string 's1' except the substring 'token'.
// const char *reverse(const char *s1, const char *token) {
//   assert(s1 && token);
//   stack<char> stack1;
//   const char *ptoken = token, *head = s1, *rear = s1;
//   while (*head != '\0') {
//     while (*head != '\0' && *ptoken == *head) {
//       ptoken++;
//       head++;
//     }
//     if (*ptoken == '\0') // contain the token
//     {
//       const char *p;
//       for (p = head - 1; p >= rear; p--)
//         stack1.push(*p);

//       ptoken = token;
//       rear = head;
//     } else {
//       stack1.push(*rear);
//       head = ++rear;
//       // ptoken = token;
//     }
//   }
//   char *return_v = new char[strlen(s1) + 1];
//   int i = 0;
//   while (!stack1.empty()) {
//     return_v[i++] = stack1.top();
//     stack1.pop();
//   }
//   return_v[i] = '\0';
//   return return_v;
// }
int main(int argc, char *argv[]) {
  Solution s;
  cout << "the sky is blue\n";
  cout << s.reverseWords("the sky is blue");
  return 0;
}
// @lc code=end
