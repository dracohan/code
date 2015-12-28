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

typedef struct bstree_node {
    int value;
    bstree_node *left;
    bstree_node *right;
} tree_node;

// 创建二元查找树
void add_bstree_node(tree_node* &p_current, int value) {
    if (NULL == p_current) {
        tree_node *node = new tree_node();
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        p_current = node;
    } else {
        if (p_current->value > value)
            add_bstree_node(p_current->left, value);
        else if (p_current->value < value)             
            add_bstree_node(p_current->right, value);
        else
            cout << "The value has already in the tree.";     
    } 

} 
// 二叉树转双向链表 
void tree_to_list(tree_node* root, tree_node* &head, tree_node* &last) 
{     
    //为空，返回
    if (!root)         
        return; 
    //不为空，转换左侧，最后的节点保存为last
    tree_to_list(root->left, head, last);
    root->left = last;
    if (last)
        last->right = root;
    else
        head = root;
    last = root;
    tree_to_list(root->right, head, last);
}

// 打印双向链表
void print_list(tree_node* head) {
    tree_node* p = head;
    while (p) {
        cout << p->value << " ";         
        p = p->right;
    }
    cout << endl;
}

int main() {
    tree_node *root = NULL;

    add_bstree_node(root, 10);
    add_bstree_node(root, 6);
    add_bstree_node(root, 14);
    add_bstree_node(root, 4);
    add_bstree_node(root, 8);
    add_bstree_node(root, 12);
    add_bstree_node(root, 16);

    tree_node* head = NULL;
    tree_node* last = NULL;
    tree_to_list(root, head, last);
    print_list(head);
}
