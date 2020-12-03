/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (38.80%)
 * Total Accepted:    137.6K
 * Total Submissions: 354.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution {
public:
    
    bool canPlaceQ(int r, int c, int n, vector<string>& mat) {
        for (int i=r-1; i>=0; i--) {
            if (mat[i][c] == 'Q') return false;
        }
        for (int i=r-1, j=c-1; i>=0 && j>=0; i--, j--) {
            if (mat[i][j] == 'Q') return false;
        }
        for (int i=r-1, j=c+1; i>=0 && j<n; i--, j++) {
            if (mat[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void doNQueens(int n, int& totC, int howmany, int r, 
                   vector<string> mat, vector<vector<string>>& ans) {
        /* base case */
        if (r == n) {
            return;
        }
    
        for (int c=0; c<n; c++) {
            if (canPlaceQ(r, c, n, mat)) {
                mat[r][c] = 'Q';
                if ((howmany+1) == n) {
                    totC++;
                    ans.push_back(mat);
                    return;
                }
                doNQueens(n, totC, howmany+1, r+1, mat, ans);
                mat[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        int totC = 0;
        vector<string> mat;
        vector<vector<string>> ans;
        
        for (int i=0; i<n; i++) {
            string s;
            for (int j=0; j<n; j++) {
                s += ".";
            }
            mat.push_back(s);
        }
        
        doNQueens(n, totC, 0, 0, mat, ans);
        cout << totC << endl;
        return ans;
    }
};
