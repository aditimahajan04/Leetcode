class Solution {
public:
    int countPrimes(int n) {
        vector<int> p(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(p[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    p[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(p[i]==1){
                ans++;
            }
        }
        return ans;
    }
};