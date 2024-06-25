class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Min-heap to store the next cell to process in the format {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        // Initialize the distance matrix with a large value
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0; // Start from the top-left corner with zero effort

        // Push the starting cell into the priority queue
        pq.push({0, {0, 0}});

        // Directions for moving in the grid (up, right, down, left)
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Process the cells in the priority queue
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first; // Current effort to reach this cell
            int row = it.second.first;
            int col = it.second.second;

            // If we have reached the bottom-right corner, return the effort
            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            // Explore the 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Check if the new cell is within the grid bounds
                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    // Calculate the effort to move to the new cell
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the previously recorded effort, update the distance
                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};