/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (26.73%)
 * Total Accepted:    248K
 * Total Submissions: 911.8K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You must return the copy of the given head as a reference to the cloned
 * list.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*
 * Two approach
 * 1. Create a duplicate list by running through the next pointer
 *    Use a map for old_pointer -> new_pointer
 *    Get random pointer for each node and assign the mapped pointer for the new list
 *
 * 2. Create a duplicate list by running through the next pointer
 *    Interleave the list A -> A' -> B -> B' -> C -> C' -> NULL
 *    new_node->rand_ptr = old_node->rand_ptr->next;
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node head2;
        Node *th2, *th = head;
        while (th) {
            th2 = new Node();
            th2->val = th->val;
            th2->next = th->next;
            th->next = th2;
            th = th2->next;
        }

        th = head;
        while (th) {
            th2 = th->next;
            th2->random = th->random ? th->random->next : NULL;
            th = th2->next;
        }

        th = head;
        if (th)
            head2.next = th->next;
        else
            head2.next = NULL;

        while (th) {
            th2 = th->next;
            th->next = th2->next;
            th = th->next;
            if (th) {
                th2->next = th->next;
            } else {
                th2->next = NULL;
            }
        }
        return head2.next;
    }
};
