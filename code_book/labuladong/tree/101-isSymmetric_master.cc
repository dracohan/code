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
class Solution {
 public:
  bool isSymmetric(TreeNode* root) { return (isMirror(root, root)); }

  bool isMirror(TreeNode* ln, TreeNode* rn) {
    if (ln == nullptr && rn == nullptr) return true;
    if (ln == nullptr || rn == nullptr) return false;
    if (ln->val != rn->val) return false;

    return (isMirror(ln->left, rn->right) && isMirror(ln->right, rn->left));
  }
};