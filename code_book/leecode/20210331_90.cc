// 给你一个整数数组 nums
// ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

// 示例 1：

// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subsets-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  static vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> rec;
    map<int, int> hash;
    for (int i = 1; i <= 10; i++) {
      hash[i]++;
    }
    for (int i = 1; i <= 10; i++) {
      if (hash[i] != 0) {
        rec.push_back(i);
        res.push_back(rec);
      }
    }
    for (int i = 1; i <= 10; i++) {
      
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> res = subsetsWithDup(nums);
  for (auto v : res) {
    for (auto n : v) {
      std::cout << n << ", "
    }
    std::cout << std::endl;
  }
}