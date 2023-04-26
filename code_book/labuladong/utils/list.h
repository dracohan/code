#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *l) {
  while (l != nullptr) {
    std::cout << l->val << " ";
    l = l->next;
  }
  std::cout << std::endl;
}


