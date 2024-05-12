class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans(2*n,-1);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && s.top() <=nums[i]) s.pop();

            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(nums[i]);
        }
        ans.resize(n);
        return ans;
    }
};