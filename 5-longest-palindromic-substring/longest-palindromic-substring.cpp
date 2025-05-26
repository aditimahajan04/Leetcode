class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int start = 0;
        int maxLen = 1; 

        for (int i = 0; i < s.length(); ++i) { 
            int l_odd = i - 1;
            int r_odd = i + 1;
            while (l_odd >= 0 && r_odd < s.length() && s[l_odd] == s[r_odd]) {
                if (r_odd - l_odd + 1 > maxLen) {
                    maxLen = r_odd - l_odd + 1;
                    start = l_odd;
                }
                l_odd--;
                r_odd++;
            }

            int l_even = i;
            int r_even = i + 1;
            while (l_even >= 0 && r_even < s.length() && s[l_even] == s[r_even]) {
                if (r_even - l_even + 1 > maxLen) {
                    maxLen = r_even - l_even + 1;
                    start = l_even;
                }
                l_even--;
                r_even++;
            }
        }

        return s.substr(start, maxLen);
    }
};