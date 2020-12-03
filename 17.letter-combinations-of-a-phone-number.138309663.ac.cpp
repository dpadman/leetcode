/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.24%)
 * Total Accepted:    377.6K
 * Total Submissions: 915.6K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:    
    vector<string> letterCombinations(string d) {
        int num;
        vector<string> res;
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        num = d[d.size()-1]-48;
        for (int i=0; i<m[num].size(); i++) {
            res.push_back(string(1,m[num][i]));
        }
        
        for (int i=d.size()-2; i>=0; i--) {
            num = d[i]-48;
            vector<string> out = res;
            res.clear();
            for (int j=0; j<m[num].size(); j++) {
                for (int k=0; k<out.size(); k++) {
                    string s(1, m[num][j]);
                    s += out[k];
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};
