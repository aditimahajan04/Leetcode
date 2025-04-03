class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q; // Min Heap
    
    for(int num : nums) {
        q.push(num);
        if(q.size() > k) q.pop(); // Keep only k largest elements
    }
    
    return q.top(); // Smallest in k-size heap = K-th largest in array
}

};