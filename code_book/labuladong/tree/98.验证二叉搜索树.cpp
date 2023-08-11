/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (37.06%)
 * Likes:    2119
 * Dislikes: 0
 * Total Accepted:    756.6K
 * Total Submissions: 2M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
#include <unordered_map>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr, nullptr); }

  // 限定以 root 为根的子树节点必须满足 max->val > root->val > min->val
  bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
    // base case
    if (root == nullptr)
      return true;
    // 若 root->val 不符合 max 和 min 的限制，说明不是合法 BST
    if (min != nullptr && root->val <= min->val)
      return false;
    if (max != nullptr && root->val >= max->val)
      return false;
    // 限定左子树的最大值是 root->val，右子树的最小值是 root->val
    return isValidBST(root->left, min, root) &&
           isValidBST(root->right, root, max);
  }
};

int main() {
  vector<int> vec = {10, 5, 15, 8888, 8888, 6, 20};
  TreeNode* t = vecToTree(vec);
//   printTreePreOrder(t);
  Solution s; 
  auto res = s.isValidBST(t);
  std::cout << "val:" << res << std::endl;
}

// @lc code=end
