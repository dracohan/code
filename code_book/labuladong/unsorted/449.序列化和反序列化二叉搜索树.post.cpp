/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (60.51%)
 * Likes:    480
 * Dislikes: 0
 * Total Accepted:    57.1K
 * Total Submissions: 92.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 *
 * 设计一个算法来序列化和反序列化 二叉搜索树 。
 * 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 *
 * 编码的字符串应尽可能紧凑。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 *
 *
 * 示例 2：
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
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
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
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/tree.h"
#include "../utils/utils.h"

using namespace std;
class Codec {
public:
  const string SEP = ",";
  const string NUL = "#";
  string res;
  string serialize(TreeNode *root) {
    traverse(root);
    return res;
  }

  void traverse(TreeNode *root) {
    if (root == nullptr) {
      res += NUL + SEP;
      return;
    }
    traverse(root->left);
    traverse(root->right);
    res += to_string(root->val) + SEP;
    return;
  }

  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    std::vector<std::string> tokens;
    std::istringstream iss(data);
    std::string token;

    while (std::getline(iss, token, ',')) {
      tokens.push_back(token);
    }
    // std::reverse(tokens.begin(), tokens.end());
    return build(tokens);
  }

  TreeNode *build(vector<string> &nodes) {
    if (nodes.empty())
      return nullptr;

    string first = nodes.back();
    nodes.pop_back();
    if (first == NUL)
      return nullptr;
    TreeNode *root = new TreeNode(stoi(first));

    root->left = build(nodes);
    root->right = build(nodes);

    return root;
  }
};

int main() {
  vector<int> vec = {2, 1, 3};
  TreeNode *t = buildFrom(vec);
  Codec s;
  auto res = s.serialize(t);
  std::cout << "serial:" << res << std::endl;

  TreeNode *n = s.deserialize(res);
  printTreePreOrder(n);
}
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
