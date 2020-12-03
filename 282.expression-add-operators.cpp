/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (32.63%)
 * Total Accepted:    67K
 * Total Submissions: 205.4K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 * 
 * Example 1:
 * 
 * 
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"] 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 * 
 * Example 3:
 * 
 * 
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 * 
 * Example 4:
 * 
 * 
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: num = "3456237490", target = 9191
 * Output: []
 * 
 * 
 */
class Solution {
private:
    void check(string num, string str, int& val, int nidx, int oidx, int sz, int target, vector<string> &res) {
        if (oidx > 2)
            return;
        if (nidx == sz) {
            if (val == target) {
                res.push_back(str);
            }
            return;
        } else {
            if (oidx == 0)
            val += num[nidx]-48;
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        int val = 0;
        vector<string> res;
        if (num.size() == 0)
            return res;
        if (num.size() == 1) {
            if (target == (num[0]-48)) {
                res.push_back(num);
            }
            return res;
        }
        check(num, str, val, 0, 0, num.size(), target, res);
        return res;
    }
};
