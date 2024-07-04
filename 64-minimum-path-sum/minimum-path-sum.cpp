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
                } else {
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? temp[j - 1] : INT_MAX;
                    temp[j] = grid[i][j] + min(up, left);
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};
