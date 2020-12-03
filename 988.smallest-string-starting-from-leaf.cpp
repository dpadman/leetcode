/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (47.63%)
 * Total Accepted:    14.3K
 * Total Submissions: 31.6K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * Given the root of a binary tree, each node has a value from 0 to 25
 * representing the letters 'a' to 'z': a value of 0 represents 'a', a value of
 * 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller:
 * for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
 * is a node that has no children.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 8500.
 * Each node in the tree will have a value between 0 and 25.
 * 
 * 
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
    string smallestFromLeafNW(TreeNode* root) {
        if (root == NULL)
            return "";

        string ls = smallestFromLeaf(root->left);
        string rs = smallestFromLeaf(root->right);

        if (ls == "" && rs == "")
            return ls.append(string(1,'a'+root->val));
        else if (ls == "")
            return rs.append(string(1,'a'+root->val));
        else if (rs == "")
            return ls.append(string(1,'a'+root->val));

        ls.append(string(1,'a'+root->val));
        rs.append(string(1,'a'+root->val));

        if (ls < rs)
            return ls;
        else
            return rs;
    }
public:
    void dfs(TreeNode *r, string ss, string &ans) {
        if (r == NULL)
            return;

        ss.append(string(1, 'a'+r->val));
        dfs(r->left, ss, ans);
        dfs(r->right, ss, ans);

        if (r->left == NULL && r->right == NULL) {
            reverse(ss.begin(), ss.end());
            if (ans == "" || ss < ans) {
                ans = ss;
            }
            return;
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "", ss = "";
        dfs(root, ss, ans);
        return ans;
    }
};
