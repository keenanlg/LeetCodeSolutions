// Last updated: 1/15/2026, 6:15:01 PM
class Solution {
public:
    //Check if a queen can be placed in position (r, c)
    bool niceSpot(vector<vector<int>> &board, int r, int c, int n) {
        //Check column
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 1) {
                return false;
            }
        }

        //Check upper left diagonal
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        //Check upper right diagonal
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    //Recursive helper to build solutions
    void solve(vector<vector<int>> &board, int r, int n, vector<vector<string>> &solutions) {
        if (r == n) {
            //Convert board to vector<string>
            vector<string> oneSolution;
            for (int i = 0; i < n; i++) {
                string row = "";
                for (int j = 0; j < n; j++) {
                    row += (board[i][j] == 1) ? 'Q' : '.';
                }
                oneSolution.push_back(row);
            }
            solutions.push_back(oneSolution);
        }

        for (int c = 0; c < n; c++) {
            if (niceSpot(board, r, c, n)) {
                board[r][c] = 1; //Place queen
                solve(board, r + 1, n, solutions);
                board[r][c] = 0;
            }
        }
    }

    //Main function to return all solutions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> solutions;
        solve(board, 0, n, solutions);
        return solutions;
    }
};