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
 * 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
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
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;
class Codec {
public:
const string SEP = ",";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        string res = to_string(root->val) + SEP + left + SEP + right;
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        std::vector<std::string> tokens;
        tokens = split(data, SEP);
        // std::istringstream iss(data);
        // std::string token;

        // while (std::getline(iss, token, ',')) {
        //     tokens.push_back(token);
        // }
        return build(tokens, 0, tokens.size() - 1);
    }

    vector<string> split(const string& s, const string& sep) {
        vector<string> res;
        int left = 0, right = 0;
        while ((right = s.find(sep, left)) != string::npos) {
            res.push_back(s.substr(left, right - left));
            left = right + sep.length();
        }
        res.push_back(s.substr(left, s.size() - left));
        return res;
    }

    TreeNode* build(const vector<string>& nodes, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(stoi(nodes[start]));
        int index = start, i = start + 1;
        while (i <= end) {
            if (stoi(nodes[i]) < stoi(nodes[start])) index = i;
            else break;;
            i++;
        }
        root->left = build(nodes, start + 1, index);
        root->right = build(nodes, index + 1, end);
        return root;
    }
};


int main() {
  vector<int> vec = {2,1,3};
  TreeNode* t = buildFrom(vec);
//   printTreePreOrder(t);
  Codec s; 
  auto res = s.serialize(t);
  std::cout << "serial:" << res << std::endl;

  TreeNode* n = s.deserialize(res);
  printTreePreOrder(n);
}
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

