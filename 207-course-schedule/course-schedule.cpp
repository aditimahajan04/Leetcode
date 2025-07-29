class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        vector<int> adj[N];
        for(auto  prerequisite:prerequisites){
            int course= prerequisite[0];
            int prereq= prerequisite[1];
            adj[course].push_back(prereq);
        }

        vector<int> indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }

        vector<int> topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(topo.size()==N){
	        return true;
	    }
	    return false;
    }
};