class Solution {
    int myAtoi(string s, int sign, int i, int result) {

        if (i >= s.size() || s[i] < '0' || s[i] > '9')
            return sign * result;

        int tmp = s[i] - '0';
        if (result > INT_MAX / 10 || result == INT_MAX / 10 && tmp > 7)
            return sign > 0 ? INT_MAX : INT_MIN;

        return myAtoi(s, sign, i + 1, result * 10 + tmp);
    }

public:
    int myAtoi(string s) {
        
        int i = 0, n = s.size(), sign = 1;
        while (i < n && s[i] == ' ')
            ++i;

        if (s[i] == '-')
            sign = -1, ++i;
        else if (s[i] == '+')
            ++i;

        return myAtoi(s, sign, i, 0);
    }
};