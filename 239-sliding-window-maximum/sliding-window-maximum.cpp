class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> output;
        std::deque<int> q; // Deque to store indices

        int l = 0, r = 0;

        while (r < nums.size()) {
            // Pop smaller values from q
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            q.push_back(r);

            // Remove left val from window if it's out of bounds
            if (l > q.front()) {
                q.pop_front();
            }

            // If window size is achieved, record the max value
            if ((r + 1) >= k) {
                output.push_back(nums[q.front()]);
                l++;
            }

            r++;
        }

        return output;
    }
};