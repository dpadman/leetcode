/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (28.69%)
 * Total Accepted:    206.7K
 * Total Submissions: 720.2K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int piv, s=0, e;
        bool found = false;
        for (piv=1; piv<=nums.size(); piv++) {
            for (e=nums.size()-1; s<=e; ) {
                if (nums[s] == piv || nums[e] == piv) found = true;
                
                if (nums[s] > piv && nums[e] <= piv) {
                    int k = nums[s];
                    nums[s] = nums[e];
                    nums[e] = k;
                }
                if (nums[s] <= piv) s++;
                if (nums[e] > piv) e--;
            }

            if (!found) return piv;
            else found = false;
            s = e;
            e = nums.size()-1;
        }
        return piv;
    }
};
