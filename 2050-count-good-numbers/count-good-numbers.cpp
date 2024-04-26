class Solution {
public:
    long long int power(long long x, long long n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        long long int val=power(x,n/2);
        if(n%2==0){
            return (val*val)%1000000007;
        }
        else{
            return (val*val*x)%1000000007;
        }
    }
    int countGoodNumbers(long long n) {
        long long int even=(n+1)/2;
        long long int odd=n/2;
        return (power(5,even)*power(4,odd))%1000000007;
    }
};