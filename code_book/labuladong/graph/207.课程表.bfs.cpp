/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (53.56%)
 * Likes:    1657
 * Dislikes: 0
 * Total Accepted:    312.7K
 * Total Submissions: 583.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 *
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites
 * 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须
 * 先学习课程  bi 。
 *
 *
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *
 *
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程
 * 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> g(numCourses); //邻接表存储图结构
    vector<int> indeg(numCourses);     //每个点的入度
    vector<int> res;                   //存储结果序列

    for (auto &p : prerequisites) {
      g[p[1]].push_back(p[0]);
      indeg[p[0]]++;
    }

    queue<int> q;
    //一次性将入度为0的点全部入队
    for (int i = 0; i < numCourses; i++) {
      if (indeg[i] == 0)
        q.push(i);
    }

    while (q.size()) {
      int t = q.front();
      q.pop();
      res.push_back(t);
      //删除边时，将终点的入度-1。若入度为0，果断入队
      for (int i = 0; i < g[t].size(); i++) {
        int j = g[t][i];
        indeg[j]--;
        if (indeg[j] == 0) {
          q.push(j);
        }
      }
    }
    if (res.size() == numCourses)
      return true;
    else
      return false;
  }
};
// @lc code=end
