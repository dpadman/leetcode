/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.20%)
 * Total Accepted:    226.6K
 * Total Submissions: 750.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    void printRes(vector<int>& res) {
        for (int i=0; i<res.size(); i++) cout << res[i] << ",";
        cout << endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = 0, m = matrix.size();
        int turn, pj, pk, pm, pn;
        vector <int> res;
        
        if (m)
            n = matrix[0].size();
        pm = m-1, pn = n-1, pj = 0, pk = 0;
        
        if (m == 0 || n == 0) return res;
        
        if (m == 1 || n == 1) {
            for (int i=0; i<m; i++) for (int j=0; j<n; j++) res.push_back(matrix[i][j]);
            return res;
        }
        
        while(true) {
            for (turn=0; turn<4; turn++) {
                if (turn == 0) {
                    for (int i=pk; i<pn; i++) res.push_back(matrix[pk][i]);
                } else if (turn == 1) {
                    for (int i=pj; i<pm; i++) res.push_back(matrix[i][pn]);
                } else if (turn  == 2) {
                    for (int i=pn; i>pk; i--) res.push_back(matrix[pm][i]);
                } else {
                    for (int i=pm; i>pj; i--) res.push_back(matrix[i][pj]);
                }
            }
            pm -= 1;
            pn -= 1;
            pk++;
            pj++;
            if (pj >= pm || pk >= pn) break;
        }
        
        if (pm == pj) {
            for (int i=pk; i<=pn; i++) res.push_back(matrix[pk][i]);
        } else if (pn == pj) {
            for (int i=pj; i<=pm; i++) res.push_back(matrix[i][pj]);
        }
        return res;
    }
};
