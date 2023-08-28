/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.69%)
 * Likes:    1778
 * Dislikes: 0
 * Total Accepted:    866.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> level;
    while (!q.empty()) {
      TreeNode *tmp = q.front();
      q.pop();
      level.push_back(tmp->val);
      if (tmp->left != nullptr)
        q.push(tmp->left);
      if (tmp->right != nullptr)
        q.push(tmp->right);
    }
    return level;
  }
};

int main() {
  vector<int> vec = {3, 9, 20, 8888, 8888, 15, 7};
  TreeNode *t = buildFrom(vec);
  Solution s;
  auto res = s.levelOrder(t);
  printCollection(res);
}
// @lc code=end
