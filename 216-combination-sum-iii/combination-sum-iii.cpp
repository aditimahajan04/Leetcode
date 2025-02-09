class Solution {
public:
    void solve(int idx ,int sum, int k, int n, vector<int> &cur, vector<vector<int>> & ans){
        if(cur.size() ==k){
            if(sum==n){
                ans.push_back(cur);
            }
            return;
        }
        for(int i=idx;i<=9;i++){
            if(sum+i>n){
                break;
            }
            cur.push_back(i);
            solve(i+1,sum+i,k,n,cur,ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(1,0,k,n,current,ans);
        return ans;
    }
};