/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (72.55%)
 * Total Accepted:    11.7K
 * Total Submissions: 16.1K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* constructBST(vector<int>& pre, int low, int hi) {
        if (idx == pre.size() || pre[idx] > hi || pre[idx] < low)
            return NULL;
        int val = pre[idx++];
        TreeNode *head = new TreeNode(val);
        head->left = constructBST(pre, low, val);
        head->right = constructBST(pre, val, hi);
        return head;
    }
public:
    int idx;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return constructBST(preorder, -999999, 999999);
    }
};
