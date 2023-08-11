/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (67.62%)
 * Likes:    2102
 * Dislikes: 0
 * Total Accepted:    483.5K
 * Total Submissions: 714.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *
 * k
 * 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 *
 * 提示：
 *
 *
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 *
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
public:
  ListNode *reverse(ListNode *a, ListNode *b) {
    ListNode *cur = a;
    ListNode *pre = nullptr;
    ListNode *nxt = a;

    while (cur != b) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    return pre;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *a = head;
    ListNode *b = head;
    int n = k;
    while (n-- != 0) {
      if (b == nullptr)
        return a;
      b = b->next;
    }

    ListNode *newHead = reverse(a, b);
    a->next = reverseKGroup(b, k);

    return newHead;
  }
};


int main() {
  ListNode *ll = nullptr;

  for (int i = 6; i > 0; i = i - 1) {
    ll = new ListNode(i, ll);
  }

  printList(ll);

  Solution s;
  ListNode *m = s.reverseKGroup(ll, 2);
  printList(m);
}
// @lc code=end
