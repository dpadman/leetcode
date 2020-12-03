/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (70.74%)
 * Total Accepted:    25.8K
 * Total Submissions: 36.5K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * You have a list of words and a pattern, and you want to know which words in
 * words matches the pattern.
 * 
 * A word matches the pattern if there exists a permutation of letters p so
 * that after replacing every letter x in the pattern with p(x), we get the
 * desired word.
 * 
 * (Recall that a permutation of letters is a bijection from letters to
 * letters: every letter maps to another letter, and no two letters map to the
 * same letter.)
 * 
 * Return a list of the words in words that match the given pattern. 
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a ->
 * m, b -> e, ...}. 
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
 * permutation,
 * since a and b map to the same letter.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 50
 * 1 <= pattern.length = words[i].length <= 20
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
        int len = pat.size();
        vector<string> res;
        
        for (int i=0; i<words.size(); i++) {
            
            bool m = true;
            unordered_map<char, char> mp;
            unordered_map<char, char> mpw;

            for (int j=0; (j<len) && (len == words[i].size()); j++) {
                auto it = mp.find(pat[j]);
                auto itw = mpw.find(words[i][j]);
                
                if (it == mp.end() && itw == mpw.end()) {
                    mp[pat[j]] = words[i][j];
                    mpw[words[i][j]] = pat[j];
                } else if (it == mp.end() && itw->second != pat[j]) {
                    m = false;
                    break;
                } else if (itw == mp.end() && it->second != words[i][j]) {
                    m = false;
                    break;
                } else if (itw->second != pat[j] || it->second != words[i][j]) {
                    m = false;
                    break;
                }
            }
            
            if (m)
                res.push_back(words[i]);
        }
        
        return res;
    }
};
