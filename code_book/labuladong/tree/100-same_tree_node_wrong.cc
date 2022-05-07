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
/// 结构不同，但是元素相同的两棵树
#include "../utils/tree.h"
#include "../utils/utils.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      vector<int> v1;
      vector<int> v2;

      treeToList(p, v1);
      treeToList(q, v2);
      std::sort(v1.begin(), v1.end());
      std::sort(v2.begin(), v2.end());
      return v1 == v2;
    }

    void treeToList(TreeNode* p, vector<int> &v) {
      if (nullptr == p) 
        return;
      v.push_back(p->val);
      treeToList(p->left, v);
      treeToList(p->right, v);
    }


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
  std::cout << "same tree: " << s.isSameTree(tree1->root, tree2->root) << std::endl;
}