/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (52.32%)
 * Total Accepted:    357.7K
 * Total Submissions: 682.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = nums.size();
        int powset = 1<<sz;
        ans.push_back(vector<int>());

        for (int i=1; i<powset; i++) {
            int k=i, c=0;
            ans.push_back(vector<int>());

            while (k) {
                if (k & 0x1) {
                    ans[i].push_back(nums[c]);
                }
                k >>= 1;
                c++;
            }
        }
        return ans;
    }
};
