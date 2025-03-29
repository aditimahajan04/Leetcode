#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int l = 0, r = 0;
        vector<int> lastIndex(256, -1); 
        
        while (r < n) {
            if (lastIndex[s[r]] != -1 && lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            lastIndex[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};
