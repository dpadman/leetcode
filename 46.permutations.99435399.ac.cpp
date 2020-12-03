/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.69%)
 * Total Accepted:    367.6K
 * Total Submissions: 672.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
    
    void do_permutation(vector<int>& nums, vector<vector<int>>& ans, int s, int e) {
        if (s == e) {
            ans.push_back(nums);
        } else {
            for (int i=s; i<=e; i++) {
                swap(nums, i, s);
                do_permutation(nums, ans, s+1, e);
                swap(nums, i, s);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        do_permutation(nums, ans, 0, nums.size()-1);
        return ans;
    }
};
