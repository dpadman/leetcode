/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (48.85%)
 * Total Accepted:    145.4K
 * Total Submissions: 296.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * Note:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *t, *oh = head, *eh, *to, *te;
        if (head && head->next) {
            eh = oh->next;
        } else {
            return oh;
        }

        to = oh;
        te = eh;
        to->next = te->next;
        to = to->next;
        while (to) {
            te->next = to->next;
            te = te->next;
            if (te) {
                to->next = te->next;
                to = to->next;
            } else {
                to = NULL;
            }
        }
        to = oh;
        while (to && to->next != NULL) {
            to = to->next;
        }
        to->next = eh;
        return oh;
    }
};
