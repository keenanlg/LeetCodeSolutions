// Last updated: 1/15/2026, 6:15:03 PM
class Solution {
public:
    //Determines if a queen can be placed in a spot or not
    bool niceSpot(vector<vector<int>> &board, int r, int c, int n) {
        //Checks the up direction
        for (int i = r; i >= 0; i--) {
            if (board[i][c] == 1) {
                return false;
            }
        }

        //Checks up left diagonal direction
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        //Checks up right diagonal direction
        for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    //A recursive function that finds all of the solutions of the n queens problem
    int permutation(vector<vector<int>> &board, int r, int n) {
        int solutions = 0;

        //Base case to end recursion
        if (r == n) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (niceSpot(board, r, i, n)) {
                //Places a queen in that spot
                board[r][i] = 1;
                //Recursive call to place the rest of the queens on the board
                solutions += permutation(board, r + 1, n);
                //Clears the board for more solutions to be found
                board[r][i] = 0;
            }
        }
        return solutions;
    }

    int totalNQueens(int n) {
        //Creates the chess board
        vector<vector<int>> board(n, vector<int>(n, 0));

        return permutation(board, 0, n);
    }
};