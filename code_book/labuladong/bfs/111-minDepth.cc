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
  int minDepth(TreeNode* root) {
    if (nullptr == root) return 0;

    if (nullptr == root->left && nullptr == root->right)
      return 1;
      
    else if (root->left == nullptr && root->right != nullptr)
      return 1 + minDepth(root->right);
    else if (root->left != nullptr && root->right == nullptr)
      return 1 + minDepth(root->left);
    else
      return 1 + std::min(minDepth(root->left), minDepth(root->right));
  }
};

int main() {
  Tree* tree = new Tree();
  tree->insert(9);
  tree->insert(2);
  tree->insert(3);
  tree->insert(7);
  tree->insert(20);
  tree->insert(15);
  tree->printTree();
  std::cout << std::endl;

  Solution s;
  std::cout << "min depth: " << s.minDepth(tree->root) << std::endl;
}
