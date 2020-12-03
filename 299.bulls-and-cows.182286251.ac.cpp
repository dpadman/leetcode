/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (39.18%)
 * Total Accepted:    94.2K
 * Total Submissions: 240.3K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the following Bulls and Cows game with your friend: You
 * write down a number and ask your friend to guess what the number is. Each
 * time your friend makes a guess, you provide a hint that indicates how many
 * digits in said guess match your secret number exactly in both digit and
 * position (called "bulls") and how many digits match the secret number but
 * locate in the wrong position (called "cows"). Your friend will use
 * successive guesses and hints to eventually derive the secret number.
 * 
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows. 
 * 
 * Please note that both secret number and friend's guess may contain duplicate
 * digits.
 * 
 * Example 1:
 * 
 * 
 * Input: secret = "1807", guess = "7810"
 * 
 * Output: "1A3B"
 * 
 * Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
 * 
 * Example 2:
 * 
 * 
 * Input: secret = "1123", guess = "0111"
 * 
 * Output: "1A1B"
 * 
 * Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a
 * cow.
 * 
 * Note: You may assume that the secret number and your friend's guess only
 * contain digits, and their lengths are always equal.
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int a_s = 0, b_s = 0;
        unordered_map<char, int> mmap;
        for (int i=0; i<secret.size(); i++) {
            if (secret[i] == guess[i]) {
                ++a_s;
                guess[i] = 'X';
            } else {
                auto it = mmap.find(secret[i]);
                if (it == mmap.end()) {
                    mmap[secret[i]] = 1;
                } else {
                    it->second++;
                }
            }
        }
        
        for (int i=0; i<guess.size(); i++) {
            auto it = mmap.find(guess[i]);
            if (it != mmap.end()) {
                ++b_s;
                it->second--;
                if (it->second == 0)
                    mmap.erase(it);
            }
        }
        ostringstream out;
        out << a_s << "A" << b_s << "B";
        return out.str();
    }
};
