class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int i = 0;
        int sign = 1;

        // Skip leading whitespaces
        while (str[i] == ' ') {
            i++;
        }

        // Handle optional sign
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }

        // Process digits
        while (isdigit(str[i])) {
            int digit = str[i] - '0';

            // Check for overflow
            if (result > (INT_MAX - digit) / 10) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};