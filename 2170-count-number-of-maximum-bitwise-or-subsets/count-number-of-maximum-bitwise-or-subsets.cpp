class Solution {
public:
    int maxOr=0;
    int count=0;

    int backtrack(int index,int currentOr,vector<int> &nums){
        if(index==nums.size()){
            if(currentOr==maxOr) {
                return 1;
            }
            return 0;
        }

        int take=backtrack(index+1,currentOr|nums[index],nums);
        int notTake=backtrack(index+1,currentOr,nums);

        return take+notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for(int num:nums){
            maxOr=maxOr |num;
        }
        return backtrack(0, 0, nums);
    }
};