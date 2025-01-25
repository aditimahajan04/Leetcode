#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map to track characters in 't'
        vector<int> freq(128, 0);
        for (char c : t) freq[c]++; // Count occurrences of each character in 't'
        
        int n = s.size(), m = t.size();
        int left = 0, right = 0; // Pointers for the sliding window
        int start = 0;           // Start index of the minimum window
        int minLen = INT_MAX;    // Length of the minimum window
        int count = m;           // Number of characters in 't' yet to be matched

        // Expand the window by moving the 'right' pointer
        while (right < n) {
            // If the current character is needed (exists in 't'), decrease the count
            if (freq[s[right]] > 0) count--;

            // Decrease the frequency of the current character
            freq[s[right]]--;
            right++; // Expand the window

            // When the window contains all characters of 't'
            while (count == 0) {
                // Update the minimum window if the current one is smaller
                if (right - left < minLen) {
                    minLen = right - left; // Update the minimum length
                    start = left;         // Update the start index
                }

                // Contract the window by moving the 'left' pointer
                freq[s[left]]++; // Restore the frequency of the left character
                if (freq[s[left]] > 0) count++; // If it's needed, increase count
                left++; // Move the left pointer to shrink the window
            }
        }

        // If no valid window was found, return an empty string
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
