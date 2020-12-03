/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (52.22%)
 * Total Accepted:    328.8K
 * Total Submissions: 629.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
class Solution {
private:
    int bs(vector<int>& nums, int lo, int hi, int target) {
        if (hi > lo)
            return 0;
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid]) {
            return bs(nums, lo, mid-1, target);
        } else {
            return bs(nums, mid+1, hi, target);
        }
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int val;
        vector<int> ans;
        for (int i=0; i<numbers.size(); i++) {
            if ((val = bs(numbers, i+1, numbers.size()-1, target-numbers[i])) != 0) {
                ans.push_back(i+1);
                ans.push_back(val+1);
                return ans;
            }
        }
        return ans;
    }
};
