class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(1+amount);
        dp[0]=1;

        for(int c:coins){
            for(int i=c;i<=amount;i++){
                dp[i]+=dp[i-c];
            }
        }


        return dp[amount];
    }
};
