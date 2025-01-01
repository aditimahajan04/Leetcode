
class Solution {
public:
    bool check(vector<int>& nums) {

        int count =0;
        int n= nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;            // means count 1 ho jayega agr rotated array hua
            }
        }
        if(nums[n-1]>nums[0]){      // means not rotated sorted in any way !
            count++;        // count ki value = 2 ho jayegi agr yeh hogyaaa!
        }

        return count <= 1;        // max count can be 1 for rotated sorted array!!
        
    }


};
