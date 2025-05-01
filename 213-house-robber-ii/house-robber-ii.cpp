class Solution {
public:
    int robb(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) take += prev2;
            int notTake = prev;
            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin() + 1, nums.end());     // Exclude first house
        vector<int> temp2(nums.begin(), nums.end() - 1);     // Exclude last house

        return max(robb(temp1), robb(temp2));
    }
};
