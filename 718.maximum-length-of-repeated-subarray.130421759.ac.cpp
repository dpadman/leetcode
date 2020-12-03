/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (45.66%)
 * Total Accepted:    31.9K
 * Total Submissions: 70K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 * 
 * 
 */
class Solution {
private:
    void printDp(vector<vector<vector<int>>> &dp) {
        for (int i=0; i<dp.size(); i++) {
            for (int j=0; j<dp[i].size(); j++) {
                for (int k=0; k<dp[i][j].size(); k++) {
                    cout << dp[i][j][k] << " ";
                }
                cout << "endl" << endl;
            }
            cout << endl;
        }
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxlen = 0;
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<B.size(); j++) {
                if (B[j] == A[i]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    maxlen = max(maxlen, dp[i+1][j+1]);
                } else {
                    dp[i+1][j+1] = 0;
                }
            }
        }
        return maxlen;
    }
    
    /* Time-out
    int findLength(vector<int>& A, vector<int>& B) {
        int maxlen = 0;
        int len = min(A.size(), B.size());
        vector<vector<vector<int>>> dp (len, vector<vector<int>>(len));
        vector<int>&p = (len == A.size() ? A : B);
        vector<int>&q = (len == A.size() ? B : A);
        
        for (int j=0; j<p.size(); j++) {
            for (int k=0; k<q.size(); k++) {
                if (p[j] == q[k]) {
                    dp[0][j].push_back(k);
                    maxlen = max(maxlen, 1);
                }
            }
        }
        
        for (int i=1; i<len; i++) { // for all sizes
            for (int j=0; j<len; j++) { // for all elements in the smallest array
                for (int k=0; k<dp[i-1][j].size(); k++) { // compare with previous array result
                    int c=0;
                    for (int m=0; m<i+1; m++) { // check for length match
                        if (((dp[i-1][j][k]+m) < q.size()) && ((m+j) < p.size()) && q[dp[i-1][j][k]+m] == p[m+j]) c++;
                    }
                    if (c == i+1) {
                        dp[i][j].push_back(dp[i-1][j][k]);
                        maxlen = max(maxlen, c);
                    }
                }
            }
        }
        printDp(dp);

        return maxlen;
    }*/
};
