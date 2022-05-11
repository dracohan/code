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
#include "../utils/tree.h"
#include "../utils/utils.h"
#include <vector>
#include <iostream>

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    postTraverse(vec, root);
    return vec;
  }
  void postTraverse(vector<int>& vec, TreeNode* node) {
    if (nullptr == node) return;
    postTraverse(vec, node->left);
    postTraverse(vec, node->right);
    vec.push_back(node->val);
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
  // // vector<int> res = s.preorderTraversal(tree->root);
  printCollection(s.postorderTraversal(tree->root));
}