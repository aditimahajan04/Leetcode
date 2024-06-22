class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> G(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> ans;

        for(auto p:prerequisites){
            int a=p[1],b=p[0];
            G[a].insert(b);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                bool f=dfs(G,vis,ans,i);
                if(!f){
                    return{};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool dfs(vector<unordered_set<int>> &G,vector<int>&vis,vector<int> &ans,int cur){
        vis[cur]=1;
        for(auto next:G[cur]){
            if(vis[next]==1){
                return false;
            }
            if(vis[next]==2){
                continue;
            }
            if(!dfs(G,vis,ans,next)){
                return false;
            }
        }
        vis[cur]=2;
        ans.push_back(cur);
        return true;
    }
};