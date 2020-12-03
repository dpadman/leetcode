/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (51.19%)
 * Total Accepted:    123.8K
 * Total Submissions: 239.1K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
private:
    void go(vector<vector<int>>& ans, vector<int>& cur, int rem, int s0, int k0, int k, int n) {
        if (rem == 0 && k0 > k) {
            ans.push_back(cur);
            return;
        }

        if (rem < 0 || k0 > k)
            return;

        for (int i=s0; i<=(n+1-k0) && i<10 && (rem-i)>=0; i++) {
            cur.push_back(i);
            go(ans, cur, rem-i, i+1, k0+1, k, n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> ans;
        go(ans, cur, n, 1, 1, k, n);
        return ans;
    }
};
