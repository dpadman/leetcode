/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    130.7K
 * Total Submissions: 505.4K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */

class Solution {
private:
    struct sortMe {
        bool operator() (const string &i, const string &j) {
            return (i+j < j+i);
        }
    } obj;
public:
    string largestNumber(vector<int>& nums) {
        int sm = 0;
        string ans = "";
        vector<string> m;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) sm = 1;
            m.push_back(to_string(nums[i]));
        }

        if (sm == 0)
            return "0";

        sort(m.begin(), m.end(), obj);
        for (auto it=m.rbegin(); it != m.rend(); ++it)
            ans += *it;
        return ans;
    }
};



















