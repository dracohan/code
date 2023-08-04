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

#include <queue>
#include <vector>

#include "../utils/list.h"
using namespace std;

class Solution {
public:
  ListNode *findFromEnd(ListNode *head, int k) {
    ListNode *p1 = head;
    for (int i = 0; i < k; i++) {
      p1 = p1->next;
    }
    ListNode *p2 = head;
    while (p1 != nullptr) {
      p2 = p2->next;
      p1 = p1->next;
    }
    return p2;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *x = findFromEnd(dummy, n + 1);
    x->next = x->next->next;
    return dummy->next;
  }

  ListNode *removeNthFromEnd_notworking(ListNode *head, int n) {
    // ListNode* j = head;
    // for (int i = 0; i < n && j != nullptr; i++) {
    //   j = j->next;
    // }
    // if (j == nullptr) return nullptr;

    // ListNode* k = head;
    // while (j->next != nullptr) {
    //   j = j->next;
    //   k = k->next;
    // }
    // k->next = k->next->next;
    // return head;
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *fast = dummyHead;
    ListNode *slow = dummyHead;
    while (n-- && fast != NULL) {
      fast = fast->next;
    }
    fast = fast->next;
    while (fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp; //最后再删除
    return dummyHead->next;
  }
};

int main() {
  ListNode *l0 = nullptr;
  for (int i = 2; i > 0; i = i - 1) {
    l0 = new ListNode(i, l0);
  }
  printList(l0);
  Solution s;
  ListNode *m = s.removeNthFromEnd(l0, 2);
  printList(m);
}