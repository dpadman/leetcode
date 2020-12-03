/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (44.59%)
 * Total Accepted:    13.8K
 * Total Submissions: 30.2K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */
class Solution {
public:
    double largestSum(vector<int>& A, int pos, int K, int C, double sum, double avg) {
        double nsum = 0;
        double navg, ans = 0;

        if (pos == A.size()) {
            return (avg + (sum / C));
        }

        /* no cut at pos */
        nsum = sum + A[pos];
        ans = max(ans, largestSum(A, pos+1, K, C+1, nsum, avg));

        if (K == 1)
            return ans;

        /* cut at pos */
        navg = avg + (sum / C);
        ans = max(ans, largestSum(A, pos+1, K-1, 1, A[pos], navg));

        return ans;
    }
    double largestSumOfAverages_BF(vector<int>& A, int K) {
        return largestSum(A, 0, K, 0, 0, 0);
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<double> P(N+1);
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        vector<double> dp(N);
        for (int i = 0; i < N; ++i)
            dp[i] = (P[N] - P[i]) / (N - i);

        /* O(K*N^2) - repeat K times all splits */
        for (int k = 0; k < K-1; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = i+1; j < N; ++j)
                    dp[i] = max(dp[i], (P[j]-P[i]) / (j-i) + dp[j]);

        return dp[0];
    }
};














