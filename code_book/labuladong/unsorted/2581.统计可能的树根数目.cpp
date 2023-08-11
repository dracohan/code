/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 *
 * https://leetcode.cn/problems/count-number-of-possible-root-nodes/description/
 *
 * algorithms
 * Hard (58.00%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 4.4K
 * Testcase Example:  '[[0,1],[1,2],[1,3],[4,2]]\n[[1,3],[0,1],[1,0],[2,4]]\n3'
 *
 * Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1
 * 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi
 * 之间有一条边。
 *
 * Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测
 * 。每一次猜测，Bob 做如下事情：
 *
 *
 * 选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
 * Bob 猜测树中 u 是 v 的 父节点 。
 *
 *
 * Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob
 * 猜 uj 是 vj 的父节点。
 *
 * Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面
 * 至少 有 k 个猜测的结果为 true 。
 *
 * 给你二维整数数组 edges ，Bob
 * 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回
 * 0。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]],
 * k = 3 输出：3 解释： 根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4] 根为节点 1
 * ，正确的猜测为 [1,3], [1,0], [2,4] 根为节点 2 ，正确的猜测为 [1,3], [1,0],
 * [2,4] 根为节点 3 ，正确的猜测为 [1,0], [2,4] 根为节点 4 ，正确的猜测为 [1,3],
 * [1,0] 节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]],
 * k = 1 输出：5 解释： 根为节点 0 ，正确的猜测为 [3,4] 根为节点 1
 * ，正确的猜测为 [1,0], [3,4] 根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
 * 根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
 * 根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
 * 任何节点为根，都至少有 1 个正确的猜测。
 *
 *
 *
 *
 * 提示：
 *
 *
 * edges.length == n - 1
 * 2 <= n <= 10^5
 * 1 <= guesses.length <= 10^5
 * 0 <= ai, bi, uj, vj <= n - 1
 * ai != bi
 * uj != vj
 * edges 表示一棵有效的树。
 * guesses[j] 是树中的一条边。
 * guesses 是唯一的。
 * 0 <= k <= guesses.length
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses,
                int k) {
    vector<vector<int>> g(edges.size() + 1);
    for (auto &e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x); // 建图
    }

    unordered_set<long> s;
    for (auto &e : guesses)              // guesses 转成哈希表
      s.insert((long)e[0] << 32 | e[1]); // 两个 4 字节数压缩成一个 8 字节数

    int ans = 0, cnt0 = 0;
    function<void(int, int)> dfs = [&](int x, int fa) {
      for (int y : g[x])
        if (y != fa) {
          cnt0 += s.count((long)x << 32 | y); // 以 0 为根时，猜对了
          dfs(y, x);
        }
    };
    dfs(0, -1);

    function<void(int, int, int)> reroot = [&](int x, int fa, int cnt) {
      ans += cnt >= k; // 此时 cnt 就是以 x 为根时的猜对次数
      for (int y : g[x])
        if (y != fa) {
          reroot(y, x,
                 cnt - s.count((long)x << 32 | y) // 原来是对的，现在错了
                     + s.count((long)y << 32 | x)); // 原来是错的，现在对了
        }
    };
    reroot(0, -1, cnt0);
    return ans;
  }
};
// @lc code=end
