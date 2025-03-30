#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int k) {
        if (k == 0) return 0; // Edge case: If k is 0, return 0 (no valid subarray)

        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size()) {
            mpp[nums[r]]++;  // Expand window by adding nums[r]

            while (mpp.size() > k) {  // Shrink window if unique elements exceed k
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;  // Move left pointer forward
            }

            cnt += (r - l + 1);  // Count subarrays ending at r
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};
