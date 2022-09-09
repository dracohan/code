#include <algorithm>
#include <iostream>

#include "../utils/tree.h"

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* node) {
    maxDepth(node);
    return max;
  }

  int maxDepth(TreeNode* node) {
    if (nullptr == node) return 0;
    int depth_l = maxDepth(node->left);
    int depth_r = maxDepth(node->right);
    if (depth_l + depth_r > max) max = depth_l + depth_r;

    return 1 + std::max(depth_l, depth_r);
  }

  int max = 0;
};

int main() {
  Tree* tree = new Tree();
  tree->insert(9);
  tree->insert(2);
  tree->insert(1);

  tree->insert(3);
  tree->insert(7);
  tree->insert(20);
  tree->insert(15);
  tree->printTree();
  std::cout << std::endl;

  Solution s;
  std::cout << "diameter: " << s.diameterOfBinaryTree(tree->root) << std::endl;
}