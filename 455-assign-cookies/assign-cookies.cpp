class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0;
        int r = 0;
        
        // Ensure both pointers stay within bounds
        while (l < g.size() && r < s.size()) {
            if (g[l] <= s[r]) { // Assign cookie to child
                l++;  // Move to next child
                r++;  // Move to next cookie
            } else {
                r++;  // Try next larger cookie
            }
        }
        return l; // l represents the number of children satisfied
    }
};
