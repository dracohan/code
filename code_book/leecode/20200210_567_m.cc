#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  static bool checkInclusion(string s1, string s2) {
    const char* pattern = s1.c_str();
    const char* text = s2.c_str();

    int pLen = s1.size();
    int tLen = s2.size();

    int pFreq[26];
    int winFreq[26];

    for (int i = 0; i < pLen; i++) {
      pFreq[pattern[i] - 'a']++;
    }

    int pCount = 0;
    for (int i = 0; i < 26; i++) {
      if (pFreq[i] > 0) {
        pCount++;
      }
    }

    int left = 0;
    int right = 0;
    // 当滑动窗口中的某个字符个数与 s1 中对应相等的时候才计数
    int winCount = 0;
    while (right < tLen) {
      if (pFreq[text[right] - 'a'] > 0) {
        winFreq[text[right] - 'a']++;
        if (winFreq[text[right] - 'a'] == pFreq[text[right] - 'a']) {
          winCount++;
        }
      }
      right++;

      while (pCount == winCount) {
        if (right - left == pLen) {
          return true;
        }
        if (pFreq[text[left] - 'a'] > 0) {
          winFreq[text[left] - 'a']--;
          if (winFreq[text[left] - 'a'] < pFreq[text[left] - 'a']) {
            winCount--;
          }
        }
        left++;
      }
    }
    return false;
  }
};


int main() {
  // std::string s1 = "hello";
  // std::string s2 = "ooolleoooleh";

  std::string s1 = "adc";
  std::string s2 = "dcda";

  // std::string s1 = "ab";
  // std::string s2 = "eidbaooo";
  std::cout << "result: " << std::boolalpha << Solution::checkInclusion(s1, s2)
            << std::endl;
}