class Solution {
public:
    int jump(vector<int>& nums) {
        int currReach=0;
        int maxIndex=0;
        int jumps=0;

        for(int i=0;i<nums.size()-1;i++){
            maxIndex=max(maxIndex,i+nums[i]);

            if(i==currReach){
                jumps++;
                currReach=maxIndex;
            }
        }
        return jumps;
    }
};