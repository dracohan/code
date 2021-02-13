#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

int main() {
  vector<int> test = {4,3,2,7,8,2,3,1};
  // vector<int> test = {1, 1};
  vector<int> res = Solution::findDisappearedNumbers(test);
  // for (auto a : res)
  //   std::cout << a << std::endl;
}