/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (69.76%)
 * Likes:    2388
 * Dislikes: 0
 * Total Accepted:    570.6K
 * Total Submissions: 817.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <unordered_map>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int val1, int val2) {
        return find(root, val1, val2);
    }

    TreeNode* find(TreeNode* root, int val1, int val2) {
        if (root == nullptr) {
            return nullptr;
        }
        // 前序位置
        if (root->val == val1 || root->val == val2) {
            // 如果遇到目标值，直接返回
            return root;
        }
        TreeNode* left = find(root->left, val1, val2);
        TreeNode* right = find(root->right, val1, val2);
        // 后序位置，已经知道左右子树是否存在目标值
        if (left != nullptr && right != nullptr) {
            // 当前节点是 LCA 节点
            return root;
        }
        
        return left != nullptr ? left : right;
    }
};


int main() {
  vector<int> vec = {3,5,1,6,2,0,8,8888,8888,7,4};
  TreeNode* t = vecToTree(vec);
//   printTreePreOrder(t);
  Solution s; 
  auto res = s.lowestCommonAncestor(t, 5, 4);
  std::cout << "val:" << res->val << std::endl;
}
// @lc code=end

