/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (32.46%)
 * Total Accepted:    271.1K
 * Total Submissions: 834K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

/*
 * dp[0..coins][1..amt] = {
 *  [0] = {0,1,2,3,4,5,6,7,8,9,10,11},
 *  [1] = {0,1,1,2,2,3,3,4,4,5,5,6},
 *  [2] = {0,1,1,2,2,1,2,2,3,3,2,3}
 * }
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0)
            return -1;
        
        vector<vector<int>> dp (coins.size() + 1, vector<int>(amount + 1, INT_MAX));

        sort(coins.begin(), coins.end());
        for (int i=1; i<=coins.size(); i++) {
            for (int j=0; j<=amount; j++) {
                if (j == 0)
                    dp[i][j] = 0;
                else if (j-coins[i-1] >= 0 && dp[i][j-coins[i-1]] != INT_MAX) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (dp[coins.size()][amount] != INT_MAX ? dp[coins.size()][amount] : -1);
    }
};
