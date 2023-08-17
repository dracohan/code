/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * {354] 俄罗斯套娃信封问题
 *
 * https://leetcode.cn/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (37.43%)
 * Likes:    936
 * Dislikes: 0
 * Total Accepted:    105.1K
 * Total Submissions: 281.8K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i
 * 个信封的宽度和高度。
 *
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 *
 * 请计算 最多能有多少个
 * 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 *
 * 注意：不允许旋转信封。
 *
 *
 * 示例 1：
 *
 *
 * 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出：3
 * 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 *
 * 示例 2：
 *
 *
 * 输入：envelopes = [[1,1],[1,1],[1,1]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int n = envelopes.size();
    // 按宽度升序排列，如果宽度一样，则按高度降序排列
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
         });

    // 对高度数组寻找 LIS
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (envelopes[i][1] > envelopes[j][1]) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};

int main() {
  vector<vector<int>> coins = {{4,5},{4,6},{6,7},{2,3},{1,1}};
  Solution s;
  int ret = s.maxEnvelopes(coins);
  std::cout << "ret:" << ret << std::endl;
}

// @lc code=end
