/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (40.64%)
 * Total Accepted:    216.7K
 * Total Submissions: 533.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    int preInd;
    
    Solution() : preInd(0) { }
    
    int searchIndex(vector<int>& inorder, int st, int end, int root) {
        for (int i=st; i<=end; i++) 
            if (inorder[i] == root) return i;
        cout << "BADABOOMBOOM" << endl;
        return -1;
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int st, int end) {
        if (st > end) return NULL;
        TreeNode *root = new TreeNode(preorder[preInd++]);
        int inInd = searchIndex(inorder, st, end, root->val);
        root->left = buildTreeHelper(preorder, inorder, st, inInd-1);
        root->right = buildTreeHelper(preorder, inorder, inInd+1, end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size()-1);
    }
};
