class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for (int T=0; T<=amount; T++) {
            if (T % coins[0] == 0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }
        for (int ind=1; ind<n; ind++) {
            for (int T=0; T<=amount; T++) {
                int notTake = prev[T];
                int take = 1e9;
                if (T >= coins[ind]) take = 1 + curr[T-coins[ind]];
                curr[T] = min(notTake, take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans >= 1e9) return -1;
        return ans;
    }
};