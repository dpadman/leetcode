/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (42.12%)
 * Total Accepted:    201.7K
 * Total Submissions: 476.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
private:
    vector<vector<int>> subsetsWithDupWithSet(vector<int>& nums) {
        set<vector<int>> res;
        int powset = 1<<nums.size();
        res.insert(vector<int>());
        sort(nums.begin(), nums.end());
        for (int i=1; i<powset; i++) {
            int k=i, c=0;
            vector<int> cur;

            while (k) {
                if (k & 0x1) {
                    cur.push_back(nums[c]);
                }
                k >>= 1;
                c++;
            }
            res.insert(cur);
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }

    void doit(vector<vector<int>>& res, int pos, vector<int> cur, vector<int>& nums) {
        if (cur.size() <= nums.size()) {
            res.push_back(cur);
        }
        for (int i=pos; i<nums.size(); i++) {
            if (i>pos && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            doit(res, i+1, cur, nums);
            cur.pop_back();
        }
    }
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        doit(res, 0, cur, nums);
        return res;
    }
};
