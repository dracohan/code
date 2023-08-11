/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode.cn/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (61.33%)
 * Likes:    692
 * Dislikes: 0
 * Total Accepted:    97.5K
 * Total Submissions: 159K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给你一棵二叉树的根节点 root ，返回所有 重复的子树 。
 * 
 * 对于同一类的重复子树，你只需要返回其中任意 一棵 的根结点即可。
 * 
 * 如果两棵树具有 相同的结构 和 相同的结点值 ，则认为二者是 重复 的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,null,2,4,null,null,4]
 * 输出：[[2,4],[4]]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root = [2,1,1]
 * 输出：[[1]]
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：root = [2,2,2,3,null,3,null]
 * 输出：[[2,3],[3]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数在 [1, 5000] 范围内。
 * -200 <= Node.val <= 200
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
private:
    // 记录所有子树以及出现的次数
    unordered_map<string, int> subTrees;
    // 记录重复的子树根节点
    vector<TreeNode*> res;

public:
    /* 主函数 */
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }

private:
    /* 辅助函数 */
    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }

        // 先算左右子树的序列化结果
        string left = serialize(root->left);
        string right = serialize(root->right);

        string myself = left + "," + right + "," + to_string(root->val);

        int freq = subTrees[myself];
        // 多次重复也只会被加入结果集一次
        if (freq == 1) {
            res.push_back(root);
        }
        // 给子树对应的出现次数加一
        subTrees[myself]++;

        return myself;
    }
};

int main() {
  vector<int> vec = {1,2,3,4,8888,2,4,8888,8888,8888,8888,4};
  TreeNode* t = vecToTree(vec);
//   printTreePreOrder(t);
  Solution s; 
  auto res = s.findDuplicateSubtrees(t);
  for (auto x : res) {
      printTreePostOrder(x);
  }
}
// @lc code=end

