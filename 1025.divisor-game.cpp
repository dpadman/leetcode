/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (61.70%)
 * Total Accepted:    9K
 * Total Submissions: 14.5K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */
class Solution {
public:
    bool divisorGame(int N) {
        vector<int> C(1001, 0);
        C[1] = 0;
        C[2] = 1;
        C[3] = 0;
        C[4] = 1;
        C[5] = 0;
        C[6] = 1;
        for (int i=7; i<=N; i++) {
            int t = 0;
            for (int j=1; j<=(i/2); j++) {
                if (i%j == 0) {
                    t |= ((C[i-j]+1) % 2);
                    if (t) break;
                }
            }
            C[i] = t;
        }
        return C[N];
    }
};
