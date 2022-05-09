/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>

#include "../utils/tree.h"

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return convert(nums, 0, nums.size() - 1);
  }

  TreeNode* convert(vector<int>& nums, int start, int end) {
    if (end < start) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = convert(nums, start, mid - 1);
    root->right = convert(nums, mid + 1, end);
    return root;
  }

};

int main() {
  Solution s;
  std::cout << "max depth: " << s.maxDepth(tree->root) << std::endl;
}