/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
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
using namespace std;

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    // 快慢指针初始化指向 head
    ListNode* slow = head;
    ListNode* fast = head;
    // 快指针走到末尾时停止
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针走一步，快指针走两步
        slow = slow->next;
        fast = fast->next->next;
    }
    // 慢指针指向中点
    return slow;
}
};

int main() {
  ListNode* l0 = nullptr;
  for (int i = 10; i > 0; i = i - 1) {
    l0 = new ListNode(i, l0);
  }
  printList(l0);
  Solution s;
  ListNode* m = s.middleNode(l0);
  printList(m);
}

// @lc code=end

