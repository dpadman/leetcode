/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (43.25%)
 * Total Accepted:    389.3K
 * Total Submissions: 900.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool is2Symmetric(TreeNode *t1, TreeNode *t2) {
        bool lans, rans;
        if (t1 == t2)
            return true;
        if ((t1->left != NULL && t2->right == NULL) || (t1->left == NULL && t2->right != NULL))
            return false;
        if ((t1->right != NULL && t2->left == NULL) || (t1->right == NULL && t2->left != NULL))
            return false;
        if (t1->left && t1->left->val != t2->right->val)
            return false;
        if (t1->right && t1->right->val != t2->left->val)
            return false;
        
        lans = (t1->left ? is2Symmetric(t1->left, t2->right) : true);
        rans = (t1->right ? is2Symmetric(t1->right, t2->left) : true);
        
        return (lans && rans);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
            return false;
        if (root->left && root->left->val != root->right->val)
            return false;
        return is2Symmetric(root->left, root->right);
    }
};
