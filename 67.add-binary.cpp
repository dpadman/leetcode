/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.80%)
 * Total Accepted:    296.7K
 * Total Submissions: 763.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int m=a.size(), n=b.size();

        if (m == 0)
            return b;
        else if (n == 0)
            return a;
        int k = 0;
        while (m>0 && n>0) {
            k += (a[m-1]-'0') + (b[n-1]-'0');
            if (k == 3) {
                ans.push_back('1');
                k -= 2;
            } else if (k == 2) {
                ans.push_back('0');
                k = 1;
            } else {
                ans.push_back((char)(k+48));
                k = 0;
            }
            m--, n--;
        }
        while (m > 0) {
            k += (a[m-1]-'0');
            if (k == 2) {
                ans.push_back('0');
                k = 1;
            } else if (k == 1) {
                ans.push_back('1');
                k = 0;
            } else {
                ans.push_back(a[m-1]);
            }
            m--;
        }
        while (n > 0) {
            k += (b[n-1]-'0');
            if (k == 2) {
                ans.push_back('0');
                k = 1;
            } else if (k == 1) {
                ans.push_back('1');
                k = 0;
            } else {
                ans.push_back(b[n-1]);
            }
            n--;
        }

        if (k) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
