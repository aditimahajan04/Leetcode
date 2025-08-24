class Solution {
public:
    int minBitFlips(int start, int goal) {
        int r=start^goal;
        int cnt=0;
        while(r){
            cnt+=r&1;
            r=r>>1;
        }
        return cnt;
    }
};