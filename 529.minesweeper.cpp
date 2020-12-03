/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (52.50%)
 * Total Accepted:    31.9K
 * Total Submissions: 60.7K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */
class Solution {
private:
    void solve(vector<vector<char>>& board, vector<vector<char>>& A, vector<vector<int>>& F,
            vector<tuple<int, int>>& NP, tuple<int, int> t, int M, int N) {

        if (!(get<0>(t) >= 0 && get<0>(t) < M && get<1>(t) >= 0 && get<1>(t) < N))
            return;

        if (board[get<0>(t)][get<1>(t)] == 'M') {
            A[get<0>(t)][get<1>(t)] = 'X';
            return;
        } else if (board[get<0>(t)][get<1>(t)] == 'E') {
            int c = 0;
            vector<tuple<int,int>> temp;
            for (int i=0; i<8; i++) {
                int x = get<0>(t) + get<0>(NP[i]);
                int y = get<1>(t) + get<1>(NP[i]);
                if (x >= 0 && x < M && y >= 0 && y < N) {
                    if (board[x][y] == 'M') {
                        c++;
                    } else if (board[x][y] == 'E' && F[x][y] == 0) {
                        temp.push_back(make_tuple(x, y));
                    }
                }
            }
            A[get<0>(t)][get<1>(t)] = (c == 0 ? 'B' : (c+'0'));
            if (c == 0) {
                for (int i=0; i<temp.size(); i++) {
                    F[get<0>(temp[i])][get<1>(temp[i])] = 1;
                    solve(board, A, F, NP, temp[i], M, N);
                }
            }
        }
    }
    vector<vector<char>> updateBoardQ(vector<vector<char>>& board, vector<int>& click) {
        queue<tuple<int,int>> Q;
        vector<tuple<int,int>> NP;

        if (board.size() == 0)
            return board;

        int M = board.size(), N = board[0].size();
        vector<vector<int>> F(M, vector<int>(N, 0));
        vector<vector<char>> A = board;

        NP.push_back(make_tuple(1, -1));
        NP.push_back(make_tuple(0, -1));
        NP.push_back(make_tuple(-1, -1));
        NP.push_back(make_tuple(-1, 0));

        NP.push_back(make_tuple(-1, 1));
        NP.push_back(make_tuple(0, 1));
        NP.push_back(make_tuple(1, 1));
        NP.push_back(make_tuple(1, 0));

        F[click[0]][click[1]] = 1;
        Q.push(make_tuple(click[0], click[1]));

        while (!Q.empty()) {
            auto t = Q.front();
            Q.pop();

            if (board[get<0>(t)][get<1>(t)] == 'M') {
                A[get<0>(t)][get<1>(t)] = 'X';
                break;
            } else if (board[get<0>(t)][get<1>(t)] == 'E') {
                int c = 0;
                for (int i=0; i<8; i++) {
                    int x = get<0>(t) + get<0>(NP[i]);
                    int y = get<1>(t) + get<1>(NP[i]);
                    if (x >= 0 && x < M && y >= 0 && y < N) {
                        if (board[x][y] == 'E' && F[x][y] == 0) {
                            Q.push(make_tuple(x, y));
                            F[x][y] = 1;
                        } else if (board[x][y] == 'M') {
                            c++;
                        }
                    }
                }
                A[get<0>(t)][get<1>(t)] = (c == 0 ? 'B' : (c+'0'));
            }
        }
        return A;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<tuple<int,int>> NP;

        if (board.size() == 0)
            return board;

        int M = board.size(), N = board[0].size();
        vector<vector<int>> F(M, vector<int>(N, 0));
        vector<vector<char>> A = board;

        NP.push_back(make_tuple(1, -1));
        NP.push_back(make_tuple(0, -1));
        NP.push_back(make_tuple(-1, -1));
        NP.push_back(make_tuple(-1, 0));

        NP.push_back(make_tuple(-1, 1));
        NP.push_back(make_tuple(0, 1));
        NP.push_back(make_tuple(1, 1));
        NP.push_back(make_tuple(1, 0));

        F[click[0]][click[1]] = 1;
        solve(board, A, F, NP, make_tuple(click[0], click[1]), M, N);
        return A;
    }

};
