class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[i][j]; // Starting point
                    continue;
                }

                int up = INT_MAX;
                int left = INT_MAX;

                if (i > 0) {
                    up = prev[j]; // Get value from the previous row
                }

                if (j > 0) {
                    left = temp[j - 1]; // Get value from the previous column
                }

                temp[j] = grid[i][j] + min(up, left); // Correctly calculate the minimum path sum
            }
            prev = temp; // Update the previous row with the current row
        }
        return prev[n - 1]; // Return the result from the last cell of the last row
    }
};
