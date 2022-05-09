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
  bool isSymmetric(TreeNode* root) {
    if (nullptr == root) return true;

    if (root->left == nullptr && root->right == nullptr) return true;
    if (root->left == nullptr || root->right == nullptr) return false;

    return ((root->left->val == root->right->val) &&
            isNodeValEqual(root->left, root->right));
  }

  bool isNodeValEqual(TreeNode* ln, TreeNode* rn) {
    if (ln == nullptr && rn == nullptr) return true;
    if (ln == nullptr || rn == nullptr) return false;
    if (ln->val != rn->val) return false;
    if ((ln->left == nullptr && rn->right == nullptr) &&
        (ln->right == nullptr && rn->left == nullptr)) {
      return ln->val == rn->val;
    } else if ((ln->left == nullptr && rn->right != nullptr) ||
               (ln->right == nullptr && rn->left != nullptr)) {
      return false;
    } else if ((ln->left != nullptr && rn->right == nullptr) ||
               (ln->right != nullptr && rn->left == nullptr)) {
      return false;
    } else if ((ln->left == nullptr && rn->right == nullptr) &&
               (ln->right != nullptr && rn->left != nullptr)) {
      return isNodeValEqual(ln->right, rn->left);
    } else if ((ln->right == nullptr && rn->left == nullptr) &&
               (ln->left != nullptr && rn->right != nullptr)) {
      return isNodeValEqual(ln->left, rn->right);
    } else {
      if (ln->left == nullptr || rn->right == nullptr || ln->right == nullptr ||
          rn->left == nullptr)
        return false;
      return isNodeValEqual(ln->left, rn->right) &&
             isNodeValEqual(ln->right, rn->left);
    }
  }
};