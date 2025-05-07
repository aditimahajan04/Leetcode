class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];  // Start with the first element
        int currSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]); // include or start new subarray
            maxi = max(maxi, currSum); // update max
        }

        return maxi;
    }
};
