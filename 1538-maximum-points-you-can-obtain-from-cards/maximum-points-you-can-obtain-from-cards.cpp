class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long lsum = 0, rsum = 0, maxsum = 0;

        // Calculate the initial sum of the first k cards
        for(int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        
        maxsum = lsum;
        int right = cardPoints.size() - 1;

        // Slide the window from the end of the first k cards to the start
        for(int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[right];
            right--;
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};
