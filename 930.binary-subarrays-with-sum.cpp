/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 *
 * https://leetcode.com/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (37.55%)
 * Total Accepted:    10.7K
 * Total Submissions: 27.5K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * In an array A of 0s and 1s, how many non-empty subarrays have sum S?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,0,1,0,1], S = 2
 * Output: 4
 * Explanation: 
 * The 4 subarrays are bolded below:
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] is either 0 or 1.
 * 
 */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int st = 0, ans = 0, cnt = 0, N = A.size();

        for (int i=0; i<N; i++) {
            if (cnt + A[i] == S) {
                cnt += A[i];
Inc:
                ans ++;
                for (int j=st; A[j] == 0 && j<i; j++, ans++) { }
            } else if (cnt + A[i] < S) {
                cnt += A[i];
            } else {
                cnt += A[i];
                while (cnt > S && st < i) {
                    cnt -= A[st];
                    st++;
                }
                if (cnt == S)
                    goto Inc;
            }
        }
        return ans;
    }
};
