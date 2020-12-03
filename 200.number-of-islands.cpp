/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (41.19%)
 * Total Accepted:    384.8K
 * Total Submissions: 912.2K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
private:
    struct entry {
        int x;
        int y;
    };
    void traceIsland(queue<entry>& Q, vector<vector<char>>& grid, int x, int y, int& cnt) {
        entry e, ne;
        e.x = x;
        e.y = y;
        Q.push(e);

        while (!Q.empty()) {
            e = Q.front();
            Q.pop();

            grid[e.x][e.y] = 'X';

            int nx = e.x + 1;
            int ny = e.y + 0;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                ne.x = nx;
                ne.y = ny;
                Q.push(ne);
            }

            nx = e.x + 0;
            ny = e.y + 1;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                ne.x = nx;
                ne.y = ny;
                Q.push(ne);
            }

            nx = e.x - 1;
            ny = e.y + 0;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                ne.x = nx;
                ne.y = ny;
                Q.push(ne);
            }

            nx = e.x + 0;
            ny = e.y - 1;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                ne.x = nx;
                ne.y = ny;
                Q.push(ne);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        queue<entry> Q;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    traceIsland(Q, grid, i, j, cnt);
                }
            }
        }
        return cnt;
    }
};
