/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (51.55%)
 * Total Accepted:    97.1K
 * Total Submissions: 188.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
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
    
    void doNQueens(int n, int& totC, int howmany, int r, vector<string> mat) {
        /* base case */
        if (r == n) {
            return;
        }
    
        for (int c=0; c<n; c++) {
            if (canPlaceQ(r, c, n, mat)) {
                mat[r][c] = 'Q';
                if ((howmany+1) == n) {
                    totC++;
                    return;
                }
                doNQueens(n, totC, howmany+1, r+1, mat);
                mat[r][c] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int totC = 0;
        vector<string> mat;
        
        for (int i=0; i<n; i++) {
            string s;
            for (int j=0; j<n; j++) {
                s += ".";
            }
            mat.push_back(s);
        }
        
        doNQueens(n, totC, 0, 0, mat);
        return totC;
    }
};
