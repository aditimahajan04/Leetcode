class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=start^goal; // XOR to find the differing bits
        int count=0;
        while(res){
            count+=res&1; // Count the set bits
            res>>=1; // Right shift to check next bit
        }
        return count;
    }
};