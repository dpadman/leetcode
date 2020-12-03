/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.07%)
 * Total Accepted:    382.3K
 * Total Submissions: 930.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        ans = digits;
        reverse(ans.begin(), ans.end());
        if (ans.size() && ans[0] < 9) {
            ans[0]++;
            reverse(ans.begin(), ans.end());
        } else {
            int i, c = 1;
            for (i=0; i<ans.size(); i++) {
                if ((ans[i] + c) / 10 == 0) {
                    ans[i] += c;
                    c = 0;
                    break;
                } else {
                    ans[i] = 0;
                }
            }

            if (i == ans.size() && c) {
                ans.push_back(c);
            }
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};
