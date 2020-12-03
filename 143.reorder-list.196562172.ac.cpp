/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (30.51%)
 * Total Accepted:    150.9K
 * Total Submissions: 494.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int i = 0, cnt = 0;
        stack<ListNode*> sk;
        ListNode *n, *t = head;
        while (t) {
            sk.push(t);
            t=t->next;
            cnt++;
        }
        if (cnt == 1) return;
        t = head;
        while (t) {
            n = t->next;
            t->next = sk.top();
            if (t->next != n)
                t->next->next = n;
            else {
                t->next->next = NULL;
                break;
            }
            sk.pop();
            t = t->next->next;
            cnt -= 2;
            if (cnt == 1) {
                n->next = NULL;
                break;
            }
        }
    }
};
