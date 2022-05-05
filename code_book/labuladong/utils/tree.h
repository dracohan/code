// 1.cc
// 题目：
// 输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只调整指针的指向。

//    10
//    / /
//   6  14
// / / / /
// 4  8 12 16

// 转换成双向链表
// 4=6=8=10=12=14=16

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

struct Tree {
  TreeNode* root;
  Tree() : root(nullptr) {}

  void insert(int val) { insert(root, val); }

  void insert(TreeNode*& current, int val) {
    if (nullptr == current) {
      TreeNode* node = new TreeNode();
      node->left = nullptr;
      node->right = nullptr;
      node->val = val;
      current = node;
    } else {
      if (current->val > val)
        insert(current->left, val);
      else if (current->val < val)
        insert(current->right, val);
      else
        std::cout << "The val has already in the tree.";
    }
  }

  void treeToList(TreeNode*& head, TreeNode*& last) {
    treeToList(root, head, last);
  }

  void treeToList(TreeNode* root, TreeNode*& head, TreeNode*& last) {
    if (nullptr == root) return;

    //不为空，转换左侧，最后的节点保存为last
    treeToList(root->left, head, last);
    root->left = last;
    if (last)
      last->right = root;
    else
      head = root;
    last = root;
    treeToList(root->right, head, last);
  }

  void printTree() { printTree(root); }

  void printTree(TreeNode* current) {
    if (nullptr == current) return;

    printTree(current->left);
    std::cout << current->val << " ";
    printTree(current->right);
  }
};

// 打印双向链表
void printList(TreeNode* head) {
  TreeNode* p = head;
  while (p) {
    std::cout << p->val << " ";
    p = p->right;
  }
  std::cout << endl;
}