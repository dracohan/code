/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 *
 * https://leetcode.cn/problems/course-schedule-iv/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 53.4K
 * Testcase Example:  '2\n[[1,0]]\n[[0,1],[1,0]]'
 *
 * 你总共需要上 numCourses 门课，课程编号依次为
 * 0 到 numCourses-1 。你会得到一个数组 prerequisite ，其中 prerequisites[i] =
 * [ai, bi] 表示如果你想选 bi 课程，你 必须 先选 ai 课程。
 *
 *
 * 有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以
 * [0,1] 数对的形式给出先修课程数对。
 *
 *
 * 先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c
 * 的先决条件，那么课程 a 就是课程 c 的先决条件。
 *
 * 你也得到一个数组 queries ，其中 queries[j] = [uj, vj]。对于第 j
 * 个查询，您应该回答课程 uj 是否是课程 vj 的先决条件。
 *
 * 返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
 * 输出：[false,true]
 * 解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
 *
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
 * 输出：[false,false]
 * 解释：没有先修课程对，所以每门课程之间是独立的。
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
 * [[1,0],[1,2]]
 * 输出：[true,true]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 2 <= numCourses <= 100
 * 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
 * prerequisites[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * 每一对 [ai, bi] 都 不同
 * 先修课程图中没有环。
 * 1 <= queries.length <= 10^4
 * 0 <= ui, vi <= n - 1
 * ui != vi
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
  vector<vector<int>> graph;
  vector<int> visited;
  vector<int> chain;
  vector<vector<int>> chains;

public:
  void dfs(int i) {
    for (int x : graph[i]) {
      if (!visited[x]) {
        visited[x] = 1;
        dfs(x);
      }
    }
    chain.push_back(i);
  }

  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    graph.resize(numCourses);
    visited.resize(numCourses);
    for (auto pre : prerequisites) {
      int x = pre[0];
      int y = pre[1];
      graph[y].push_back(x);
    }

    for (int i = 0; i < numCourses; i++) {
      // if (!visited[i]) {
        dfs(i);
        chains.push_back(chain);
        visited.clear();
        visited.resize(numCourses);
        chain.clear();

      // }
    }

    vector<bool> res;
    for (auto &query : queries) {
      int u = query[0];
      int v = query[1];
      vector<int> prev = chains[v];
      if (std::find(prev.begin(), prev.end(), u) == prev.end())
        res.push_back(false);
      else
        res.push_back(true);
    }
    return res;
  }
};

int main() {
  vector<vector<int>> prerequisites = {{1,2},{1,0},{2,0}};
  vector<vector<int>> queries = {{1,0},{1,2}};
  Solution s;
  auto ret = s.checkIfPrerequisite(3, prerequisites, queries);
  printCollection(ret);
}


// @lc code=end
