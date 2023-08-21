/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 *
 * https://leetcode.cn/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (39.70%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    68.6K
 * Total Submissions: 172.8K
 * Testcase Example:  '4\n[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]\n0\n3\n1'
 *
 * 有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei]
 * ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
 * 
 * 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的
 * 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * 输出: 200
 * 解释: 
 * 城市航班图如下
 * 
 * 
 * 从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
 * 
 * 示例 2：
 * 
 * 
 * 输入: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * 输出: 500
 * 解释: 
 * 城市航班图如下
 * 
 * 
 * 从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 0 <= flights.length <= (n * (n - 1) / 2)
 * flights[i].length == 3
 * 0 <= fromi, toi < n
 * fromi != toi
 * 1 <= pricei <= 10^4
 * 航班没有重复，且不存在自环
 * 0 <= src, dst, k < n
 * src != dst
 * 
 * 
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
   unordered_map<int, vector<std::pair<int, int>>> hash;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (auto& f : flights) {
            hash[f[0]].push_back(std::make_pair(f[1], f[2]));
        }

        int price = 0;
        int minum = 0;
        queue<int> q;
        q.push(src);

        while(k-- > 0) {
            int cur = q.front();
            q.pop();
            vector<std::pair<int, int>> nexts = hash[cur];
            for (const auto& next : nexts) {
                q.push(next.first);
                int cost = next.second;
                price += cost;
                if (next.first == dst) {
                    minum = std::max(minum, price);
                }
            }
        }
        return minum;
    }
};

int main() {
  vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {0,2,500}};
  Solution s;
  int ret = s.findCheapestPrice(3, flights, 0, 2, 1);
  cout << "ret: " << ret << endl;
}
// @lc code=end

