/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 *
 * https://leetcode.cn/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (52.78%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    120.2K
 * Total Submissions: 228.1K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3',
 * '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0'
 * 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 *
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 *
 * 列表 deadends
 * 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 *
 * 字符串 target
 * 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回
 * -1 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * 输出：6
 * 解释：
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" ->
 * "0202"。 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * 这样的序列是不能解锁的， 因为当拨动到 "0102" 时这个锁就会被锁定。
 *
 *
 * 示例 2:
 *
 *
 * 输入: deadends = ["8888"], target = "0009"
 * 输出：1
 * 解释：把最后一位反向旋转一次即可 "0000" -> "0009"。
 *
 *
 * 示例 3:
 *
 *
 * 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * 输出：-1
 * 解释：无法旋转到目标数字且不被锁定。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= deadends.length <= 500
 * deadends[i].length == 4
 * target.length == 4
 * target 不在 deadends 之中
 * target 和 deadends[i] 仅由若干位数字组成
 *
 *
 */
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  // int openLock(vector<string>& deadends, string target) {
  //   if (target == "0000") {
  //     return 0;
  //   }

  //   unordered_set<string> deads(deadends.begin(), deadends.end());
  //   if (deads.count("0000")) {
  //     return -1;
  //   }
  //   auto num_prev = [](char x) -> char { return (x == '0' ? '9' : x - 1); };
  //   auto num_succ = [](char x) -> char { return (x == '9' ? '0' : x + 1); };

  //   auto get = [&](string& status) -> vector<string> {
  //     vector<string> ret;
  //     for (int i = 0; i < 4; ++i) {
  //       char num = status[i];
  //       status[i] = num_prev(num);
  //       ret.push_back(status);
  //       status[i] = num_succ(num);
  //       ret.push_back(status);
  //       status[i] = num;
  //     }
  //     return ret;
  //   };

  //   unordered_set<string> visited;
  //   queue<pair<string, int>> q;

  //   int step = 0;
  //   q.emplace("0000", 0);
  //   visited.insert("0000");

  //   while (!q.empty()) {
  //     auto [cur, step] = q.front();
  //     q.pop();
  //     for (auto&& next : get(cur)) {
  //       if (!visited.count(next) && !deads.count(next)) {
  //         if (next == target) {
  //           return step + 1;
  //         }

  //         q.emplace(next, step + 1);
  //         visited.insert(std::move(next));
  //       }
  //     }
  //   }
  //   return -1;
  // }

  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deads(deadends.begin(), deadends.end());
    unordered_set<string> q1, q2, visited;

    int step = 0;
    q1.insert("0000");
    q2.insert(target);

    while(!q1.empty() && !q2.empty()){
        // 哈希集合在遍历的过程中不能修改，用 temp 存储扩散结果
        unordered_set<string> temp;

        /* 将 q1 中的所有节点向周围扩散 */
        for(auto cur : q1){
            /* 判断是否到达终点 */
            if(deads.count(cur)) 
                continue;
            if(q2.count(cur))
                return step;

            visited.insert(cur);

            /* 将一个节点的未遍历相邻节点加入集合 */
            for(int j=0; j<4; j++){
                string up = plusOne(cur, j);
                if(!visited.count(up))
                    temp.insert(up);
                string down = minusOne(cur, j);
                if(!visited.count(down))
                    temp.insert(down);
            }
        }
        /* 在这里增加步数 */
        step++;
        // temp 相当于 q1
        // 这里交换 q1 q2，下一轮 while 就是扩散 q2
        q1 = q2;
        q2 = temp;
    }
    return -1;
}

};

int main() {
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";

  Solution s;
  std::cout << "need step: " << s.openLock(deadends, target) << std::endl;
}

// @lc code=end
