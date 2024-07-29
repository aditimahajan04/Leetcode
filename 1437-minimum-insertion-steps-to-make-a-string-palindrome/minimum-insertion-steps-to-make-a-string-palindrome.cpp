class Solution {
public:
    int lcs(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else{
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string str) {
        string t=str;
        reverse(str.begin(),str.end());
        return lcs(str,t);
    }
    int minInsertions(string s){
        int n=s.size();
        int k=longestPalindromeSubseq(s);
        return n-k;
    }
};