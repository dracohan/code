/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (45.29%)
 * Likes:    2018
 * Dislikes: 0
 * Total Accepted:    335.3K
 * Total Submissions: 740.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 二叉树中的 路径
 * 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中
 * 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
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
#include <iostream>
#include <map>
#include <vector>
#include <climits>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return res;
    }

    int traverse(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = std::max(0, traverse(root->left));
        int right = std::max(0, traverse(root->right));
        res = std::max(res, left + right + root->val);
        return std::max(left, right) + root->val;
    }

};

int main() {
    Tree *t = new Tree();

    t->insert(10);
    t->insert(6);
    t->insert(14);
    t->insert(4);
    t->insert(8);
    t->insert(12);
    t->insert(16);

    t->printTree();
    std::cout << std::endl;

    TreeNode* head = nullptr;
    TreeNode* last = nullptr;
    t->treeToList(head, last);
    printList(head);
}

// @lc code=end
