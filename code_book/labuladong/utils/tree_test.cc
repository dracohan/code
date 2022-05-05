#include "tree.h"

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