class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min++;
                max++;
            } else if (s[i] == ')') {
                min--;
                max--;
            } else { // when s[i] == '*'
                min--;
                max++;
            }
            if (min < 0) { // Ensure min does not go negative
                min = 0;
            }
            if (max < 0) { // If max goes negative, it's invalid
                return false;
            }
        }
        return (min == 0);
    }
};