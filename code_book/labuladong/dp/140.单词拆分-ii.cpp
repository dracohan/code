/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode.cn/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (57.35%)
 * Likes:    712
 * Dislikes: 0
 * Total Accepted:    91.4K
 * Total Submissions: 159K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个字符串 s
 * 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
 * 返回所有这些可能的句子。
 *
 * 注意：词典中的同一个单词可能在分段中被重复使用多次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * 输出:["cats and dog","cat sand dog"]
 *
 *
 * 示例 2：
 *
 *
 * 输入:s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 解释: 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 *
 * 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * 输出:[]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中所有字符串都 不同
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
  unordered_set<string> wds;
  vector<string> sentences;
  string sentense;

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    for (auto &s : wordDict)
      wds.insert(s);
    dp(s, "", 0);
    return sentences;
  }

  void dp(string s, string pre, int start) {
    if (start == s.size()) {
      sentences.push_back(pre);
      return;
    }
    for (auto &wd : wds) {
      int len = wd.size();
      if (start + len > s.size()) {
        continue;
      }
      if (wd == s.substr(start, len)) {
        dp(s, pre == "" ? wd : pre + " " + wd, start + len);
      }
    }
  }
};

int main() {
  string str = "catsanddog";
  vector<string> wordDict = {"cat","cats","and","sand","dog"};
  Solution s;
  vector<string> ret = s.wordBreak(str, wordDict);
  for (auto s : ret)
    cout << "s: " << s << endl;
    
}

// @lc code=end
