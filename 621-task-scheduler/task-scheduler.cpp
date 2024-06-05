class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> counts;
        priority_queue<int> pq;
        for(auto it:tasks){
            counts[it]++;
        }
        for(auto it:counts){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            int time=0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto it:temp){
                if(it){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                ans=ans+time;
            }
            else{
                ans=ans+n+1;
            }
        }
        return ans;
    }
};