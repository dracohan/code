/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../utils/list.h"
using namespace std;
class Solution {
public:
// 求链表的交点
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // p1 指向 A 链表头结点，p2 指向 B 链表头结点
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != p2) {
        // p1 走一步，如果走到 A 链表末尾，转到 B 链表
        if (p1 == nullptr) p1 = headB;
        else               p1 = p1->next;
        // p2 走一步，如果走到 B 链表末尾，转到 A 链表
        if (p2 == nullptr) p2 = headA;
        else               p2 = p2->next;
    }
    return p1; // 返回交点
}
};
// @lc code=end

