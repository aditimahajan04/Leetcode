class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int inc=1;
        int dec=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc =0;
            }
            if(nums[i]>nums[i+1]){
                dec=0;
            }
        }return (inc || dec);
    }
};
