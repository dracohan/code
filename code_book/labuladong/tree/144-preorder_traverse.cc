/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "../utils/tree.h"
#include "../utils/utils.h"
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      traverse(root);
      return res;
    }

    void traverse(TreeNode* node) {
      if (nullptr == node) return;
      res.push_back(node->val);
      traverse(node->left);
      traverse(node->right);
    }

    vector<int> res;
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
  // // vector<int> res = s.preorderTraversal(tree->root);
  printCollection(s.preorderTraversal(tree->root));
}