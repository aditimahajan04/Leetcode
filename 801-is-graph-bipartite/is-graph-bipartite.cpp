class Solution {
public:
    bool check(vector<vector<int>> &graph,vector<int> &colored,int start,int color){
        colored[start]=color;
        for(auto it: graph[start]){
            if(colored[it]==-1){
                if(!check(graph,colored,it,!color)){
                    return false;
                }
            }
            else if(colored[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colored[i]==-1){
                if(!check(graph,colored,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};