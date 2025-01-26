#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0); // Frequency array for characters in s1
        vector<int> window(26, 0); // Frequency array for the current window in s2
        int n1 = s1.size(), n2 = s2.size();

        if (n1 > n2) return false;
        for (char c : s1) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < n2; i++) {
            window[s2[i] - 'a']++;
            if (i >= n1) {
                window[s2[i - n1] - 'a']--;
            }
            if (freq == window) {
                return true;
            }
        }

        return false;
    }
};
