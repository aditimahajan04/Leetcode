#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool valid(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    
    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else
            return ch - 'A' + 'a';
    }
    
    bool checkPalindrome(string& s, int start, int end) {
        if (start >= end)
            return true; // Base case: start index crosses or equals end index, it's a palindrome
        
        if (!valid(s[start]))
            return checkPalindrome(s, start + 1, end); // Skip non-alphanumeric characters from start
        if (!valid(s[end]))
            return checkPalindrome(s, start, end - 1); // Skip non-alphanumeric characters from end
        
        // If both characters are valid, compare them
        if (toLowerCase(s[start]) != toLowerCase(s[end]))
            return false; // Characters don't match
        
        // Recur for the substring excluding start and end characters
        return checkPalindrome(s, start + 1, end - 1);
    }
public:
    bool isPalindrome(string s) {
        return checkPalindrome(s, 0, s.length() - 1);
    }
};