class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Right sum is the total sum minus the current element and left sum
            int rightSum = totalSum - leftSum - nums[i];
            
            if (leftSum == rightSum) {
                return i;
            }
            
            // Update left sum for the next iteration
            leftSum += nums[i];
        }
        
        return -1;
    }
};
