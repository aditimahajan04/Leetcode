class Solution {
private:
    int maxi(vector<int> arr){
        int ans = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }

    long long solve(vector<int>& arr, int mid){
        long long int total = 0;
        for(int i=0; i<arr.size(); i++){
            int y = ceil( arr[i] / (double)mid );
            total += y;
        }
        return total;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = maxi(piles);

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            long long int hours = solve(piles,mid);

            if(hours <= h){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return start;
    }
};

