class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int temp=nums[i]+nums[left]+nums[right];
                if(abs(temp-target)<abs(sum-target)){
                    sum=temp;
                }
                if(temp>target){
                    right--;
                }
                else if(temp<target){
                    left++;
                }
                else{
                    return target;
                }                
            }
        }
        return sum;
    }
};