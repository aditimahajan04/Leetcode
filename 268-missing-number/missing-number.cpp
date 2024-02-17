class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=i)
            {
                return i;
            }
            i++;
        }
        return n;
    }
};