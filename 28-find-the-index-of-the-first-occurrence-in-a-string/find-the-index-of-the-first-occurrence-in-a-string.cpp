class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.length());
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while(i<needle.length()){
            if(needle[i]==needle[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        i =0;//haystack
        int j=0;//needle
        while(i<haystack.length()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j == needle.length()) return i-j;
            }
            else{
                if(j == 0) i++;
                else j=lps[j-1];
            }
        }
        return -1;
    }
};