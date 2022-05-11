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
#include <iostream>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (nullptr == root) return nullptr;
    TreeNode* tmp = new TreeNode;
    tmp = root->left;
    // root->left = root->right;
    // root->right = tmp;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
  }
};

int main() {
  Tree* tree = new Tree();
  tree->insert(1);
  tree->insert(2);
  tree->insert(3);
  tree->printTree();
  std::cout << std::endl;

  Solution s;
  Tree* itree = new Tree();
  itree->root = s.invertTree(tree->root);

  itree->printTree();
  std::cout << std::endl;
}