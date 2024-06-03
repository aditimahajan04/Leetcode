class Solution {
public:
    int subarraysLessOrEqualToK(vector<int> &nums,int k){
        if(k==0){
            return 0;
        }
        unordered_map<int,int> mpp;
        int count=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            mpp[nums[j]]++;
            while(i<j && mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysLessOrEqualToK(nums,k)-subarraysLessOrEqualToK(nums,k-1);
    }
};