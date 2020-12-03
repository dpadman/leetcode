/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.18%)
 * Total Accepted:    215K
 * Total Submissions: 522.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    void go(set<vector<int>>& ans, vector<int> &cur, vector<int> &cand, int pos, int target) {
        if (pos == cand.size() || target < 0)
            return;
        if (target-cand[pos] == 0) {
            cur.push_back(cand[pos]);
            ans.insert(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(cand[pos]);
        go (ans, cur, cand, ++pos, target-cand[pos]);
        cur.pop_back();
        go (ans, cur, cand, pos, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        set<vector<int>> ans;
        vector<vector<int>> out;
        sort(candidates.begin(), candidates.end());
        go(ans, cur, candidates, 0, target);
        if (ans.size() > 0)
            out.assign(ans.begin(), ans.end());
        return out;
    }
};
