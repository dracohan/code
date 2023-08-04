/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode.cn/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (51.16%)
 * Likes:    1014
 * Dislikes: 0
 * Total Accepted:    230.2K
 * Total Submissions: 449.9K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
 * 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 如果 intervals 为空，则返回 0
        if (intervals.size() == 0) return 0;
        // 按照 intervals 数组中每个元素的第二个值进行升序排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        // 记录区间的数量最小为 1
        int count = 1;
        // 记录当前区间的结束时间
        int x_end = intervals[0][1];
        // 遍历 intervals 数组
        for (vector<int>& interval : intervals) {
            // 记录当前区间的开始时间
            int start = interval[0];
            // 如果当前区间的开始时间大于等于当前区间的结束时间，则表示当前区间可以选择
            if (start >= x_end) {
                count++; // 区间数量加 1
                x_end = interval[1]; // 记录当前区间的结束时间
            }
        }
        return intervals.size() - count; // 返回区间数量
    }
};
// @lc code=end

