class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the endpoints (0 and n) to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        int c = cuts.size() - 2; // Correctly calculate the number of original cuts
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0)); // Correctly size dp array

        // Fill the dp array
        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        // Return the minimum cost to cut the stick
        return dp[1][c];
    }
};
