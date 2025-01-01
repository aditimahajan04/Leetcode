class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor2 = xor2 ^ nums[i]; // XOR of array elements
            xor1 = xor1 ^ i;       // XOR of indices [0...n-1]
        }
        xor1 = xor1 ^ n;          // XOR of the last index 'n'

        return xor1 ^ xor2;       // Missing number
    }
};
