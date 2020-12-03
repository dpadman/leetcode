/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (32.78%)
 * Total Accepted:    179K
 * Total Submissions: 545.1K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nh = NULL, *g = NULL, *st = head, *end;

        if (st && st->next)
            end = st->next;
        else
            return st;

        while (end) {
            bool dup = false;
            while (end && (end->val == st->val)) {
                ListNode *t = end;
                end = t->next;
                delete t;
                dup = true;
            }
            if (dup) {
                delete st;
                st = NULL;
            }

            if (!nh) {
                nh = st;
            }

            if (!dup) {
                if (!g) {
                    g = st;
                    g->next = NULL;
                } else {
                    g->next = st;
                    g = g->next;
                }
            }
            st = end;
            if (end)
                end = end->next;
        }
        if (!nh) {
            nh = st;
        }
        if (g) {
            g->next = st;
        }
        return nh;
    }
};
