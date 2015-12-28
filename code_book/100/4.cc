// 4.cc
#include <iostream>
#include <vector>
using namespace std;

// 二叉查找树
typedef struct BSTree {
  int data;
  BSTree* left;
  BSTree* right;
} tree_node;

// 创建二元查找树
void add_BSTree_node(tree_node* &p_current, int data) {
  if (NULL == p_current) {
    tree_node *node = new tree_node();
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    p_current = node;
  } else {
    if (p_current->data > data)
      add_BSTree_node(p_current->left, data);
    else if (p_current->data < data)
      add_BSTree_node(p_current->right, data);
    else
      cout << "The data has already in the tree.";
  }
}

void find_path(tree_node* root, int target, vector<int>& path, int& current_sum) {
  if(!root)
    return;

  current_sum += root->data;
  path.push_back(root->data);

  // 是叶子节点，并且等于target
  bool is_leaf = (!root->left && !root->right);
  if(current_sum == target && is_leaf) {
    for(vector<int>::iterator it = path.begin(); it != path.end(); ++it)
      cout << *it << " ";
    cout << endl;
  }

  // 非叶子节点，遍历孩子
  if(root->left)
    find_path(root->left, target, path, current_sum);
  if(root->right)
    find_path(root->right, target, path, current_sum);

  // pop当前元素
  current_sum -= root->data;
  path.pop_back();
}

int main() {
  tree_node *root = NULL;

  add_BSTree_node(root, 14);
  add_BSTree_node(root, 16);
  add_BSTree_node(root, 5);
  add_BSTree_node(root, 3);
  add_BSTree_node(root, 11);

  vector<int> path;
  int target = 30;
  int current_sum = 0;
  find_path(root, target, path, current_sum);

  return 0;
}