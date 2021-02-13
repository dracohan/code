// ����һ���������� nums?��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ
// ����?����?���������������ǵ������±ꡣ

// ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

// ����԰�����˳�򷵻ش𰸡�

// ?

// ʾ�� 1��

// ���룺nums = [2,7,11,15], target = 9
// �����[0,1]
// ���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
// ʾ�� 2��

// ���룺nums = [3,2,4], target = 6
// �����[1,2]
// ʾ�� 3��

// ���룺nums = [3,3], target = 6
// �����[0,1]

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ori_nums = nums;
    std::sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0, j = nums.size() - 1; i < j;) {
      if ((nums[i] + nums[j]) > target) {
        j--;
      } else if ((nums[i] + nums[j]) < target) {
        i++;
      } else {
        for (int n = 0; n < nums.size(); n++) {
          if (ori_nums[n] == nums[i]) res.push_back(n);
          else if (ori_nums[n] == nums[j]) res.push_back(n);
        }
        return res;
      }
    }
    return res;
  }
};

int main() {
  // vector<int> test = {3, 2, 4};
  vector<int> test = {3, 3};
  vector<int> res = Solution::twoSum(test, 6);
  // for (auto a : res) std::cout << a << std::endl;
}
