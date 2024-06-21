#include <vector>
#include <queue>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int cnt = 0;

        // BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries and if the orange is fresh
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2; // Mark orange as rotten
                    cnt++;
                }
            }
        }

        // If not all fresh oranges have turned rotten
        if (cnt != cntFresh) {
            return -1;
        }
        return tm;
    }
};
