class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        using ULL = unsigned long long;  // alias for brevity
        vector<ULL> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int T = 0; T <= amount; T++) {
            prev[T] = (T % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {
                ULL notTake = prev[T];
                ULL take = 0;
                if (coins[ind] <= T) {
                    take = cur[T - coins[ind]];
                }
                cur[T] = take + notTake;
            }
            prev = cur;
        }

        return static_cast<int>(prev[amount]);  // cast back to int safely
    }
};
