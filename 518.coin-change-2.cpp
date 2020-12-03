/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (44.95%)
 * Total Accepted:    63.3K
 * Total Submissions: 140.8K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 */
class Solution {
public:
    int countRec(vector<int>& coins, int n, int amt) {
        if (amt == 0)
            return 1;
        if (amt < 0)
            return 0;
        if (n <= 0 && amt > 0)
            return 0;
        return (countRec(coins, n-1, amt) + countRec(coins, n, amt-coins[n-1]));
    }
    int changeRec(int amount, vector<int>& coins) {
        return countRec(coins, coins.size(), amount);
    }
    
    int count(vector<vector<int>>& dp, vector<int>& coins, int n, int amt) {
        int incl, excl;
        
        if (amt == 0)
            return 1;
        if (n <= 0 && amt > 0)
            return 0;
        
        if (dp[amt][n-1] == -1)
            dp[amt][n-1] = excl = count(dp, coins, n-1, amt);
        else
            excl = dp[amt][n-1];
        
        int namt = amt-coins[n-1];
        if (namt < 0)
            return excl;

        if (dp[namt][n] == -1)
            dp[namt][n] = incl = count(dp, coins, n, namt);
        else
            incl = dp[namt][n];

        return (excl + incl);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, -1));
        return count(dp, coins, coins.size(), amount);
    }
};
