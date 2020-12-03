/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (47.62%)
 * Total Accepted:    79.1K
 * Total Submissions: 165.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        for (int i=2; i<=n ; i++) {
            for (int j=1; j<i; j++) {
                ans[i] = max(ans[i], (max(j, ans[j]) * max(i-j, ans[i-j])));
            }
        }
        return ans[n];
    }
};
