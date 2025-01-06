class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> elements(nums1.begin(), nums1.end()); // Store elements of the first array
    unordered_set<int> intersection; // To store the intersection

    // Check for common elements in the second array
    for (int num : nums2) {
        if (elements.find(num) != elements.end()) {
            intersection.insert(num); // Add to intersection if found in the set
        }
    }

    // Convert the set to a vector to return the result
    return vector<int>(intersection.begin(), intersection.end());
    }
};