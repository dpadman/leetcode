/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (37.14%)
 * Total Accepted:    201.8K
 * Total Submissions: 541.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int smap[128], tmap[128];
        memset(smap, -1, sizeof(smap));
        memset(tmap, -1, sizeof(tmap));
        for (int i=0; i<s.size(); i++) {
            if (smap[s[i]-' '] == -1 && tmap[t[i]-' '] == -1) {
                smap[s[i]-' '] = t[i]-' ';
                tmap[t[i]-' '] = s[i]-' ';
            } else if ((smap[s[i]-' '] != (t[i]-' ')) || (tmap[t[i]-' '] != (s[i]-' ')))
                return false;
        }
        return true;
    }
};