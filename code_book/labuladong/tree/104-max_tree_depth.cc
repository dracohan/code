/**
 * Definition for a binary tree node.
 */
#include <algorithm>
#include <iostream>

#include "../utils/tree.h"

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    /* official:
   if (root == nullptr) return 0;
           return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    */
    traverse(root);
    return res;
  }

  void traverse(TreeNode* root) {
    if (root == nullptr) {
      res = std::max(res, depth);
      return;
    }
    depth++;
    traverse(root->left);
    traverse(root->right);
    depth--;
  }

  int res = 0;
  int depth = 0;
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
  // std::cout << "root: " << tree->root->val << std::endl;

  Solution s;
  std::cout << "max depth: " << s.maxDepth(tree->root) << std::endl;
}