/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (47.17%)
 * Total Accepted:    198.6K
 * Total Submissions: 420K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
private:
    void combiHelper(int n, int k, int p, vector<int>& cur, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i=p; i<=(n-k+1); i++) {
            cur.push_back(i);
            combiHelper(n, k-1, i+1, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> ans;
        combiHelper(n, k, 1, cur, ans);
        return ans;
    }
};
