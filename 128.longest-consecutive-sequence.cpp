/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (41.44%)
 * Total Accepted:    203.4K
 * Total Submissions: 490.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx=0;
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]] = 1;
        }

        for (int i=0, sz=1; i<nums.size(); i++, sz=1) {
            /* only check at the start of the sequence */
            if (mp.find(nums[i]-1) == mp.end()) {
                int k=nums[i]+1;
                while(mp.find(k) != mp.end()) {
                    sz++;
                    k++;
                }
                mx = max(mx, sz);
            }
        }
        return mx;
    }
};
