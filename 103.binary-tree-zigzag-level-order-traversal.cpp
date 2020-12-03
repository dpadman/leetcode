/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.39%)
 * Total Accepted:    217.7K
 * Total Submissions: 522.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
        TreeNode *n;
        int l;
    };
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> lv;
        vector<vector<int>> ans;
        queue<qE> Q;
        struct qE qe;
        int curl = 0;

        if (!root)
            return ans;

        /* add root */
        lv.push_back(root->val);
        qe.n = root;
        qe.l = 1;
        Q.push(qe);

        while (!Q.empty()) {
            qe = Q.front();
            Q.pop();

            if (qe.l > curl) {
                if (curl % 2 == 1)
                    reverse(lv.begin(), lv.end());
                ans.push_back(lv);

                curl = qe.l;
                lv.clear();
            }
            if (qe.n->left) {
                qE qel;
                qel.n = qe.n->left;
                qel.l = qe.l+1;
                Q.push(qel);
                lv.push_back(qel.n->val);
            }
            if (qe.n->right) {
                qE qer;
                qer.n = qe.n->right;
                qer.l = qe.l+1;
                Q.push(qer);
                lv.push_back(qer.n->val);
            }
        }

        if (lv.size()) {
            if (curl % 2 == 1)
                reverse(lv.begin(), lv.end());
            ans.push_back(lv);
            lv.clear();
        }
        return ans;
    }
};
