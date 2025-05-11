class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = 0, el2 = 1;  // use different dummy values initially

        for (int num : nums) {
            if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
            else if (cnt1 == 0) {
                el1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                el2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify actual counts
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            else if (num == el2) cnt2++;  // use else-if to avoid double-counting if el1 == el2
        }

        int n = nums.size();
        vector<int> result;
        if (cnt1 > n / 3) result.push_back(el1);
        if (cnt2 > n / 3) result.push_back(el2);

        sort(result.begin(), result.end());  // optional if sorted output is needed
        return result;
    }
};
