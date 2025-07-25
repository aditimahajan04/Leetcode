class Solution {
public:
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe1(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Check left row
        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Check lower-left diagonal
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    // Recursive function to solve N-Queens column by column
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe1(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    // Main function to initiate board and start solving
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};
