class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.length();
        if(length==0){
            return true;
        }
        int start = 0; int end = length - 1;
        while(start < end){
            if(!((s[start] >= 'a' && s[start] <= 'z') || (s[start] >= 'A' && s[start] <= 'Z') || (s[start] >= '0' && s[start] <= '9'))){
                start++;
                continue;
            }
            else if(!((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= '0' && s[end] <= '9'))){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};