class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l = 0, r = 0, minLen = INT_MAX, sIndex = -1, cnt = 0;
        int n = s.size();
        int m = t.size();

        // Fix: Use m instead of n for initializing hash table
        for (int i = 0; i < m; i++) { 
            hash[t[i]]++;  
        }

        while (r < n) { 
            if (hash[s[r]] > 0) cnt++;  
            hash[s[r]]--; 

            while (cnt == m) {  
                if (r - l + 1 < minLen) {  
                    minLen = r - l + 1;  
                    sIndex = l;  
                }
                
                hash[s[l]]++;  // Restore character before moving left pointer
                if (hash[s[l]] > 0) cnt--;  
                l++;  
            }
            r++;  // Move right pointer after processing
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
