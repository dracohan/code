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
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    treeToList(p, q);
    return res;
  }

  void treeToList(TreeNode* p, TreeNode* q) {
    if (nullptr == p && nullptr != q) res = false;
    if (nullptr == q && nullptr != p) res = false;
    if (nullptr == p || nullptr == q) return;
    if (res == false) return;
    if (p->val != q->val) res = false;
    treeToList(p->left, q->left);
    treeToList(p->right, q->right);
  }

  bool res = true;
};

int main() {
  Tree* tree1 = new Tree();
  tree1->insert(9);
  tree1->insert(2);
  tree1->insert(3);
  tree1->insert(7);
  tree1->insert(20);
  tree1->insert(15);
  Tree* tree2 = new Tree();
  tree2->insert(7);
  tree2->insert(3);
  tree2->insert(15);
  tree2->insert(20);
  tree2->insert(2);
  tree2->insert(9);
  // tree->printTree();
  // std::cout << "root: " << tree->root->val << std::endl;

  Solution s;
  // // vector<int> res = s.preorderTraversal(tree->root);
  std::cout << "same tree: " << s.isSameTree(tree1->root, tree2->root)
            << std::endl;
}