#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void backtrace(vector<int>& c, vector<int>& t, vector<vector<int>>& res) {
  if (t.size() == c.size()) {
    res.push_back(t);
    return;
  }

  for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++){
    auto f_res = std::find(std::begin(t), std::end(t), *it);
    // if (f_res != std::end(t)) continue;
    t.push_back(*it);
    backtrace(c, t, res);
    t.pop_back();
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> t;
  backtrace(nums, t, res);
  return res;
}

int main() {
  vector<int> c = {1, 2, 5};
  vector<vector<int>> res = permute(c);
  for (auto it = res.begin(); it != res.end(); it++){
    for (auto tt = it->begin(); tt != it->end(); tt++){
      std::cout << *tt << " ";
    }
    std::cout << std::endl;
  }
}
