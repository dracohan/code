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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for (auto head : lists) {
      if (head) pq.push(head);
    }

    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      p->next = node;
      if (node->next) {
        pq.push(node->next);
      }
      p = p->next;
    }
    return dummy->next;
  }

 private:
  struct compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
  };
};

int main() {
  ListNode* l0 = nullptr;
  ListNode* l1 = nullptr;
  ListNode* l2 = nullptr;
  for (int i = 10; i > 0; i = i - 3) {
    l0 = new ListNode(i, l0);
  }
  for (int i = 9; i > 0; i = i - 3) {
    l1 = new ListNode(i, l1);
  }
  for (int i = 8; i > 0; i = i - 3) {
    l2 = new ListNode(i, l2);
  }
  printList(l0);
  std::cout << std::endl;
  printList(l1);
  std::cout << std::endl;
  printList(l2);
  std::cout << std::endl;
  vector<ListNode*> lists;
  lists.push_back(l0);
  lists.push_back(l1);
  lists.push_back(l2);
  Solution s;
  ListNode* m = s.mergeKLists(lists);
  printList(m);
}