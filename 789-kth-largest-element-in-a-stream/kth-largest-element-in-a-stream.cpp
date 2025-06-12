class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto l:nums){
            pq.push(l);
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        while(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

