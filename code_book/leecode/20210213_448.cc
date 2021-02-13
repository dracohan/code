// ����һ����Χ��? 1 �� a[i] �� n (?n = �����С ) �� �������飬�����е�Ԫ��һЩ���������Σ���һЩֻ����һ�Ρ�

// �ҵ������� [1, n] ��Χ֮��û�г����������е����֡�

// �����ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�ΪO(n)�������������������? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�

// ʾ��:

// ����:
// [4,3,2,7,8,2,3,1]

// ���:
// [5,6]


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