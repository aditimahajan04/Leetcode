class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> ngeMap;  // Stores next greater elements for nums2
        stack<int> st;

        // Compute next greater elements for nums2
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            ngeMap[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Map results to nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};
