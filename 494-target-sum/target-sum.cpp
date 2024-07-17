class Solution {
public:
    int mod=1e9+7;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        if(totSum-target<0 || (totSum-target)%2 !=0){
            return 0;
        }
        int sum=(totSum-target)/2;
        vector<int> prev(sum+1,0);
        if(nums[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
        }
        if(nums[0]!=0 && nums[0]<=sum){
            prev[nums[0]]=1;
        }
        for(int ind=1;ind<n;ind++){
            vector<int> cur(sum+1,0);
            for(int tar=0;tar<=sum;tar++){
                int notTaken=prev[tar];
                int taken=0;
                if(nums[ind]<=tar){
                    taken=prev[tar-nums[ind]];
                }
                cur[tar]=(notTaken+taken)%mod;
            }
            prev=cur;
        }
        return prev[sum];
    }
};