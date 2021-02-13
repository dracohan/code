#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> findDisappearedNumbers(vector<int> &nums) {
    int len = nums.size();
    int exp = 1;
    vector<int> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++) {
      if (nums[i] == exp) {
        exp++;
      } else if (nums[i] < exp) {
        continue;
      } else if (nums[i] > exp) {
        for (int j = exp; j < nums[i]; j++) {
          res.push_back(j);
        }
        exp = nums[i] + 1;
      }
    }
    for (int k = exp; k <= len; k++) res.push_back(k);
    return res;
  }
};

int main() {
  // vector<int> test = {4,3,2,7,8,2,3,1};
  vector<int> test = {1, 1};
  vector<int> res = Solution::findDisappearedNumbers(test);
  // for (auto a : res)
  //   std::cout << a << std::endl;
}