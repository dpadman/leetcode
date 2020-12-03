/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.87%)
 * Total Accepted:    348.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string str) {
        int s=0, e=str.size()-1;

        while (s <= e) {
            if (!((str[s] >= 'A' && str[s] <= 'Z') ||
                    (str[s] >= 'a' && str[s] <= 'z') ||
                    (str[s] >= '0' && str[s] <= '9'))) {
                s++;
            } else if (!((str[e] >= 'A' && str[e] <= 'Z') ||
                    (str[e] >= 'a' && str[e] <= 'z') ||
                    (str[e] >= '0' && str[e] <= '9'))) {
                e--;
            } else if (str[s] == str[e]) {
                s++;
                e--;
            } else if ((str[e] >= 'A' && str[e] <= 'Z') &&
                    ((str[e]+32) == str[s])) {
                s++;
                e--;
            } else if ((str[e] >= 'a' && str[e] <= 'z') &&
                    ((str[e]-32) == str[s])) {
                s++;
                e--;
            } else {
                return false;
            }
        }

        return true;
    }
};































