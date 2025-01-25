#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int l = 0; // Left pointer of the window
        
        // Array to keep track of characters in the window (ASCII size 256)
        bool seen[256] = {false}; // Initially, no character is seen
        
        for (int r = 0; r < n; r++) { // Right pointer of the window
            // If the character s[r] is already in the window, move left pointer
            while (seen[s[r]]) {
                seen[s[l]] = false; // Remove s[l] from the window
                l++; // Shrink the window from the left
            }
            
            // Mark the character s[r] as seen
            seen[s[r]] = true;
            
            // Calculate the maximum length of the window
            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
