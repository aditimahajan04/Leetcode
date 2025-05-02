class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns

        vector<vector<int>> dp(n, vector<int>(m, 0)); // DP table

        // Initialize the first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the DP table row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // From directly above
                int up = dp[i - 1][j];

                // From top-left diagonal
                int leftDiagonal = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;

                // From top-right diagonal
                int rightDiagonal = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;

                // Minimum path sum to reach (i, j)
                dp[i][j] = matrix[i][j] + min({up, leftDiagonal, rightDiagonal});
            }
        }

        // Find the minimum value in the last row
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};
