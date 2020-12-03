/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (40.11%)
 * Total Accepted:    237.3K
 * Total Submissions: 591K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void swap(vector<int>& nums, int p1, int p2) {
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
    }

    void do_permutation(vector<int> nums, vector<vector<int>>& ans, int s, int e) {
        if (s == e) {
            ans.push_back(nums);
        } else {
            for (int i=s; i<=e; i++) {
                if (i == s || (nums[i] != nums[s] && nums[i-1] != nums[i])) {
                    swap(nums, i, s);
                    do_permutation(nums, ans, s+1, e);
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do_permutation(nums, ans, 0, nums.size()-1);
        return ans;
    }
};
