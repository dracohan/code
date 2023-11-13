/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (71.80%)
 * Likes:    1138
 * Dislikes: 0
 * Total Accepted:    319.8K
 * Total Submissions: 445.4K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
 * postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
 *
 *
 */

// @lc code=start
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
  unordered_map<int, int> index;

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); i++) {
      index[inorder[i]] = i;
    }
    return build(inorder, 0, inorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }

  TreeNode *build(vector<int> &inorder, int inStart, int inEnd,
                  vector<int> &postorder, int postStart, int postEnd) {
    int rootVal = postorder[postEnd];
    int inOrderRootIndex = index[rootVal];

    TreeNode *root = new TreeNode(rootVal);
    int leftTreeSize = inOrderRootIndex - inStart;

    root->left = build(inorder, inStart, inOrderRootIndex - 1, postorder,
                       postStart, postStart + leftTreeSize - 1);
    root->right = build(inorder, inOrderRootIndex + 1, inEnd, postorder,
                        postStart + leftTreeSize, postEnd - 1);
    return root;
  }
};

int main() {
  vector<int> inOrder = {9,3,15,20,7};
  vector<int> postOrder = {9,15,7,20,3};
  Solution s; 
  auto res = s.buildTree(inOrder, postOrder);
  printTreePreOrder(res);
}


// @lc code=end
