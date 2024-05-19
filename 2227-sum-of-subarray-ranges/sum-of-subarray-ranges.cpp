class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       int n = nums.size();
       vector<int> leftMin(n,-1);
       vector<int> rightMin(n,n);
       vector<int> leftMax(n,-1);
       vector<int> rightMax(n,n);
       stack<int> st;
       for(int i=0;i<n;i++) {
           while(!st.empty() && nums[i]<=nums[st.top()]) {
               st.pop();
           }
           if(st.empty()) leftMin[i] = i+1;
           else leftMin[i] = i-st.top();
           st.push(i);
       } 
       stack<int> st2;
        for(int i=n-1;i>=0;i--) {
           while(!st2.empty() && nums[i]<nums[st2.top()]) {
               st2.pop();
           }
           if(st2.empty()) rightMin[i] = n-i;
           else rightMin[i] = st2.top()-i;
           st2.push(i);
       }
       stack<int> st3;
       stack<int> st4;
       for(int i=0;i<n;i++) {
           while(!st3.empty() && nums[i]>=nums[st3.top()]) {
               st3.pop();
           }
           if(st3.empty()) leftMax[i] = i+1;
           else leftMax[i] = i-st3.top();
           st3.push(i);
       }
        for(int i=n-1;i>=0;i--) {
           while(!st4.empty() && nums[i]>nums[st4.top()]) {
               st4.pop();
           }
           if(st4.empty()) rightMax[i] = n-i;
           else rightMax[i] = st4.top()-i;
           st4.push(i);
       }
       long long sum = 0;
       for(int i=0;i<n;i++) {
           long long prod = (long long)nums[i] * leftMin[i] * rightMin[i];
           long long prod1 = (long long)nums[i] * leftMax[i] * rightMax[i];
           sum -= prod;
           sum += prod1;
       }
        return sum;
    }
};