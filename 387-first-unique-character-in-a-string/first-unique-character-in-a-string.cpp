class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> check;
        for(char i:s){
            check[i]++;
        }
        for(int i=0;i<s.length();i++){
            if(check[s[i]]==1) return i;
        }
        return -1;
    }
};