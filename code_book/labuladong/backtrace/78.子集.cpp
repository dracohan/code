/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> track;
  vector<vector<int>> result;
  vector<vector<int>> subsets(vector<int> &nums) {
    backtrace(nums, 0);
    return result;
  }

  void backtrace(vector<int> &nums, int start) {
    result.push_back(track);
    // if (n == nums.size()) return;
    for (int i = start; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrace(nums, i + 1);
      track.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> c = {1, 2, 5};
  vector<vector<int>> res = s.subsets(c);
  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto tt = it->begin(); tt != it->end(); tt++) {
      std::cout << *tt << " ";
    }
    std::cout << std::endl;
  }
}

// @lc code=end
