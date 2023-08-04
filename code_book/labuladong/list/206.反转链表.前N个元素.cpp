/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (73.53%)
 * Likes:    3258
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
 *
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
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

#include "../utils/list.h"
#include "../utils/utils.h"
using namespace std;

class Solution {
  ListNode* successor = nullptr;
public:
  ListNode *reverseN(ListNode *head, int n) {
    if (n == 1) {
      successor = head->next;
      return head;
    }
    ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;
    return last;
  }
};

int main() {
  ListNode *l0 = nullptr;

  for (int i = 6; i > 0; i = i - 1) {
    l0 = new ListNode(i, l0);
  }

  printList(l0);

  Solution s;
  ListNode *m = s.reverseN(l0, 3);
  printList(m);
}
// @lc code=end
