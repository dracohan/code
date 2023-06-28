/*
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

  for 选择 in 选择列表:
      # 做选择
      将该选择从选择列表移除
      路径.add(选择)
      backtrack(路径, 选择列表)
      # 撤销选择
      路径.remove(选择)
      将该选择再加入选择列表
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// typedef std::function<void()> func_t;
void backtrace(vector<int>& c, vector<int>& t, vector<vector<int>>& res) {
  if (t.size() == c.size()) {
    res.push_back(t);
    return;
  }

  for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++) {
    auto f_res = std::find(std::begin(t), std::end(t), *it);
    if (f_res != std::end(t)) continue;
    t.push_back(*it);
    backtrace(c, t, res);
    t.pop_back();
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> res;
  vector<int> track;
  backtrace(nums, track, res);

  // func_t backtrace = [&]() {
  //   if (track.size() == nums.size()) {
  //     res.push_back(track);
  //     return;
  //   }
  //   for (auto it = nums.begin(); it != nums.end(); it++) {
  //     if (std::find(track.begin(), track.end(), *it) != track.end())
  //       continue;
  //     track.push_back(*it);
  //     backtrace();
  //     track.pop_back();
  //   }
  // };
  // backtrace();
  return res;
}

int main() {
  vector<int> c = {1, 2, 5};
  vector<vector<int>> res = permute(c);
  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto tt = it->begin(); tt != it->end(); tt++) {
      std::cout << *tt << " ";
    }
    std::cout << std::endl;
  }
}
