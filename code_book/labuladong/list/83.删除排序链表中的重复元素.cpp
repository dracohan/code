/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码已经通过力扣的测试用例，应该可直接成功提交。
// #include <cstddef>
#include "../utils/list.h"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {  // 删除链表中重复的元素
        if (head == NULL) return NULL;  // 如果链表为空，直接返回NULL
        ListNode *slow = head, *fast = head;  // 定义快慢指针，初始都指向头结点
        while (fast != NULL) {  // 只要快指针没有遍历完整个链表
            if (fast->val != slow->val) {  // 快慢指针值不同
                slow->next = fast;  // 慢指针连接新节点
                slow = slow->next;  // 慢指针向后移动一位
            }
            fast = fast->next;  // 快指针向后移动一位
        }
        slow->next = NULL;  // 断开与后面重复元素的连接
        return head;  // 返回头结点
    }
};
// @lc code=end

