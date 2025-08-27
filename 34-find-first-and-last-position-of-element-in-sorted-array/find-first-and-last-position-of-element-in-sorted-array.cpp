class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        int low=0;
        int high=n-1;

        int fp=-1;
        int lp=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                fp=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        low=0;
        high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                lp=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        ans.push_back(fp);
        ans.push_back(lp);
        return ans;
    }
};