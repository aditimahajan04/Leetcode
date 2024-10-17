class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        } 
        priority_queue <pair<int,int> >pq;   
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;  
    }
};