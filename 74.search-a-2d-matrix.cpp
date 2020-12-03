/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.82%)
 * Total Accepted:    224.2K
 * Total Submissions: 642.5K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
private:
    int rowMatch(vector<vector<int>>& matrix, int target, int st, int end) {
        int mid = -1, n = matrix[0].size();
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                break;
            } else if (target > matrix[mid][n-1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return mid;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        if (m == 1 && matrix[0].size() == 0)
            return false;
        int rowNum = rowMatch(matrix, target, 0, m-1);
        if (rowNum == -1)
            return false;
        int mid = -1, st = 0, end = matrix[rowNum].size()-1;
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (target == matrix[rowNum][mid])
                return true;
            else if (target > matrix[rowNum][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};
