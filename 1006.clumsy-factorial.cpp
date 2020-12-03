/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 *
 * https://leetcode.com/problems/clumsy-factorial/description/
 *
 * algorithms
 * Medium (53.95%)
 * Total Accepted:    6.5K
 * Total Submissions: 12.1K
 * Testcase Example:  '4'
 *
 * Normally, the factorial of a positive integer n is the product of all
 * positive integers less than or equal to n.  For example, factorial(10) = 10
 * * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
 * 
 * We instead make a clumsy factorial: using the integers in decreasing order,
 * we swap out the multiply operations for a fixed rotation of operations:
 * multiply (*), divide (/), add (+) and subtract (-) in this order.
 * 
 * For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However,
 * these operations are still applied using the usual order of operations of
 * arithmetic: we do all multiplication and division steps before any addition
 * or subtraction steps, and multiplication and division steps are processed
 * left to right.
 * 
 * Additionally, the division that we use is floor division such that 10 * 9 /
 * 8 equals 11.  This guarantees the result is an integer.
 * 
 * Implement the clumsy function as defined above: given an integer N, it
 * returns the clumsy factorial of N.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 7
 * Explanation: 7 = 4 * 3 / 2 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 12
 * Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10000
 * -2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a
 * 32-bit integer.)
 * 
 * 
 */
class Solution {
public:
    int clumsy(int N) {
        int c=0, i, ans;
        vector<int> q;
        for (i=N; (i-4)>0; i-=4) {
            ans = i;
            ans *= (i-1);
            ans /= (i-2);
            q.push_back(ans);
            q.push_back(i-3);
        }
        ans = i;
        if ((i-1)>0)
            ans *= (i-1);
        if ((i-2)>0)
            ans /= (i-2);
        q.push_back(ans);
        if ((i-3)>0)
            q.push_back(i-3);
        ans = q[0];
        for (i=1; (i+1)<q.size(); i+=2) {
            ans += q[i];
            ans -= q[i+1];
        }
        if (i<q.size())
            ans += q[i];
        return ans;
    }
};
