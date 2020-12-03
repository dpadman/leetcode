/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (56.21%)
 * Total Accepted:    448.3K
 * Total Submissions: 796.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> inorderTraversalR(TreeNode* root) {
        vector<int> res;
        helperR(root, res);
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        if (!root) return res;

        sk.push(root);
        while (root->left != NULL) {
            sk.push(root->left);
            root=root->left;
        }
        while (!sk.empty()) {
            root=sk.top();
            sk.pop();
            res.push_back(root->val);
            if (root->right != NULL) {
                sk.push(root->right);
                root=root->right;
                while (root->left != NULL) {
                    sk.push(root->left);
                    root=root->left;
                }
            }
       }
        return res;
    }
private:
    void helperR(TreeNode *r, vector<int>& res) {
        if (!r) return;
        helperR(r->left, res);
        res.push_back(r->val);
        helperR(r->right, res);
    }
};
