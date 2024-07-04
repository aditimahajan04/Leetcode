class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0); // Initialize a vector to store the previous row's path counts

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0); // Initialize a temporary vector for the current row
            for (int j = 0; j < n; j++) {
                // Base conditions
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                } else if (i == 0 && j == 0) {
                    temp[j] = 1; // If we are at the starting point, there is one path to it
                } else {
                    int up = 0;
                    int left = 0;

                    // Check if we can move up and left (if not at the edge of the maze)
                    if (i > 0) {
                        up = prev[j]; // Number of paths from above (previous row)
                    }
                    if (j > 0) {
                        left = temp[j - 1]; // Number of paths from the left (current row)
                    }

                    // Total number of paths to reach (i, j) is the sum of paths from above and left
                    temp[j] = up + left;
                }
            }
            prev = temp; // Update the previous row with the current row
        }

        // The final result is stored in prev[n - 1], which represents the destination in the last row
        return prev[n - 1];
    }
};
