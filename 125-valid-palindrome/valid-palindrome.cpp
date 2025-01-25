#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    // Helper function to check if a character is alphanumeric
    bool valid(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    
    // Helper function to convert a character to lowercase
    char toLowerCase(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 'a';
        return ch; // Already lowercase or a digit
    }

public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start < end) {
            // Move start pointer to the next valid character
            while (start < end && !valid(s[start])) {
                start++;
            }
            
            // Move end pointer to the previous valid character
            while (start < end && !valid(s[end])) {
                end--;
            }
            
            // Compare the characters after converting them to lowercase
            if (toLowerCase(s[start]) != toLowerCase(s[end])) {
                return false; // Not a palindrome
            }
            
            // Move pointers closer to the center
            start++;
            end--;
        }
        
        return true; // String is a palindrome
    }
};
