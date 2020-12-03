/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (39.77%)
 * Total Accepted:    63.5K
 * Total Submissions: 159.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
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
    void dd(TreeNode *root, int key) {
        if (!root)
            return;
        else if (root->left && root->left->val == key) {
            TreeNode *r = root->left->right;
            if (root->left->left) {
                root->left = root->left->left;
                TreeNode *lr = root->left->right;
                if (r)
                    root->left->right = r;
                if (lr && r) {
                    while (r->left != NULL)
                        r = r->left;
                    r->left = lr;
                }
            } else {
                root->left = root->left->right;
            }
        } else if (root->right && root->right->val == key) {
            TreeNode *r = root->right->right;
            if (root->right->left) {
                root->right = root->right->left;
                TreeNode *rr = root->right->right;
                if (r)
                    root->right->right = r;
                if (rr && r) {
                    while (r->left != NULL)
                        r = r->left;
                    r->left = rr;
                }
            } else {
                root->right = root->right->right;
            }
        } else if (key < root->val) {
            dd(root->left, key);
        } else {
            dd(root->right, key);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        } else if (root->val == key) {
            if (!root->right)
                return root->left;
            if (!root->left)
                return root->right;
            TreeNode *r = root->right;
            root->val = root->left->val;
            TreeNode *lr = root->left->right;
            root->left = root->left->left;
            while (r->left != NULL) {
                r = r->left;
            }
            r->left = lr;
        } else {
            dd(root, key);
        }
        return root;
    }
};
