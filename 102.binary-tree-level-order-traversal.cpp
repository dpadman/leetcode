/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.08%)
 * Total Accepted:    368.2K
 * Total Submissions: 764.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    struct qE {
        TreeNode *node;
        int level;
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int cur_level = 0;
        vector<vector<int>> ans;
        vector<int> cur;
        queue<qE> Q;
        qE e;

        if (!root)
            return ans;

        e.node = root;
        e.level = 0;
        Q.push(e);
        while (!Q.empty()) {
            e = Q.front();
            Q.pop();

            if (cur_level != e.level) {
                ans.push_back(cur);
                cur.clear();
                cur_level = e.level;
            }
            cur.push_back(e.node->val);
            if (e.node->left) {
                qE el;
                el.node = e.node->left;
                el.level = e.level + 1;
                Q.push(el);
            }
            if (e.node->right) {
                qE er;
                er.node = e.node->right;
                er.level = e.level + 1;
                Q.push(er);
            }
        }

        if (cur.size())
            ans.push_back(cur);

        return ans;
    }
};
