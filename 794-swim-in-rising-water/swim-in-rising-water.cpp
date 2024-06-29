class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isValid(int nrow, int ncol, int n){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        int start=grid[0][0],end=grid[n-1][n-1];

        int time[n*n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                time[grid[i][j]]=i*n+j;
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int t=0;t<n*n;t++){
            int row=time[t]/n;
            int col=time[t]%n;

            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(isValid(nrow,ncol,n) && grid[nrow][ncol]<=t){
                    ds.unionBySize(t,grid[nrow][ncol]);
                }
            }
            if(ds.findUPar(start)==ds.findUPar(end)) return t;
        }
        return (n*n) -1;
    }
};