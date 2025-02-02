/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "../utils/list.h"
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    // smaller splitted list 1
    ListNode* dummy1 = new ListNode(-1);
    // larger splitted list 2
    ListNode* dummy2 = new ListNode(-1);
    // moving header
    ListNode *p1 = dummy1, *p2 = dummy2;
    // original header
    ListNode* p = head;
    while (p != nullptr) {
      if (p->val >= x) {
        p2->next = p;
        p2 = p2->next;
      } else {
        p1->next = p;
        p1 = p1->next;
      }
      // p= p->next(tmp), but p1/p2->next should be nullptr
      ListNode* tmp = p->next;
      p->next = nullptr;
      p = tmp;
    }
    // concat two list
    p1->next = dummy2->next;
    // dummy1 is virtual
    return dummy1->next;
  }
};

int main() {
  ListNode* l0 = nullptr;
  for (int i = 1; i < 10; i = i + 1) {
    l0 = new ListNode(i, l0);
  }
  printList(l0);
  std::cout << std::endl;
  Solution s;
  ListNode* m = s.partition(l0, 5);
  printList(m);
}