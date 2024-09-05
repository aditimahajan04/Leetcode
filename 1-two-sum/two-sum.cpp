class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Stores the number and its index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                // If complement is found, return its index and the current index
                return {map[complement], i};
            }
            // Otherwise, store the current number with its index
            map[nums[i]] = i;
        }
        return {}; // Return empty if no solution found
    }
};
