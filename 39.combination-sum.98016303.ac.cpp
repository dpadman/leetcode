/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.97%)
 * Total Accepted:    331.1K
 * Total Submissions: 690.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    void printTemp(vector<int>& temp) {
        for (int i=0; i<temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    
    void comSum(vector<int>& cand, int t, int c, vector<int> temp, set<vector<int>> &ans) {

        if (c == t) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }

        if (c > t) return;

        for (int i=0; i<cand.size(); i++) {
            temp.push_back(cand[i]);
            comSum(cand, t, c+cand[i], temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> s;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        comSum(candidates, target, 0, temp, s);

        ans.assign(s.begin(), s.end());
        return ans;
    }
};
