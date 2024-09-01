class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);  // dp[i] stores the minimum cuts needed for the substring s[i...n-1]
        dp[n] = 0;  // No cuts needed for an empty substring

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {  // Corrected: `j` starts from `i` and goes up to `n-1`
                if (isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];  // 1 cut + result of the substring from j+1 to n-1
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;  // Subtract 1 because no cut is needed for a single palindrome
    }
};
