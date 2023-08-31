/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)   
            return false;
        
        if (A->val == B->val && compare(A, B))
            return true;
        
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool compare(TreeNode* A, TreeNode* B) {
        if(B == nullptr)
            return true;
        if(A != nullptr && B != nullptr)
            if (A->val == B->val) {
                return compare(A->left, B->left) && compare(A->right, B->right);
            }
        return false;        
    }
};

int main() {
  vector<int> vec1 = {10,12,6,8,3,11};
  TreeNode* t1 = buildFrom(vec1);
  vector<int> vec2 = {10,12,6,8};
  TreeNode* t2 = buildFrom(vec2);
//   printTreePreOrder(t);
  Solution s; 
  auto res = s.isSubStructure(t1, t2);
  std::cout << "val:" << res << std::endl;
}



