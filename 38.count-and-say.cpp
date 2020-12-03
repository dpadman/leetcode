/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (40.22%)
 * Total Accepted:    276.3K
 * Total Submissions: 686.8K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i=2; i<=n; i++) {
            int j, k=1;
            string cur;

            for (j=1; j<ans.size(); j++) {
                if (ans[j] != ans[j-1]) {
                    cur += (k+48);
                    cur += ans[j-1];
                    k=1;
                } else {
                    k++;
                }
            }
            cur += (k+48);
            cur += ans[j-1];
            ans = cur;
        }
        return ans;
    }
};

/*
int main(void) {
    Solution S;
    cout << "Result " << S.countAndSay(2) << endl;
    return 0;
}
*/
