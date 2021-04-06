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

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
  vector<int> test = {3, 2, 4};
  // vector<int> test = {3, 3};
  vector<int> res = Solution::twoSum(test, 6);
  for (auto a : res) std::cout << a << std::endl;
}
