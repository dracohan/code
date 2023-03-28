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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr)
      return list2;

    if (list2 == nullptr)
      return list1;

    ListNode *head = nullptr;
    if (list1->val > list2->val) {
      head = list2;
      list2 = list2->next;
    } else {
      head = list1;
      list1 = list1->next;
    }
    
    ListNode *dummy = head;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val > list2->val) {
        head->next = list2;
        list2 = list2->next;
      } else {
        head->next = list1;
        list1 = list1->next;
      }
      head = head->next;
    }
    if (list1 != nullptr)
      head->next = list1;
    if (list2 != nullptr)
      head->next = list2;
    return dummy;
  }
};

int main() {
  ListNode *l0 = nullptr;
  ListNode *l1 = nullptr;
  for (int i = 10; i > 0; i = i - 2) {
    l0 = new ListNode(i, l0);
  }
  for (int i = 9; i > 0; i = i - 2) {
    l1 = new ListNode(i, l1);
  }
  printList(l0);
  std::cout << std::endl;
  printList(l1);
  std::cout << std::endl;
  Solution s;
  ListNode *m = s.mergeTwoLists(l0, l1);
  printList(m);
}