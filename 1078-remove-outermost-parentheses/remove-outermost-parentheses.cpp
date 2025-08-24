class Solution {
public:
    string removeOuterParentheses(string s) {
        int t=0;
        string ans="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && t==0){
                t++;
            }
            else if(s[i]=='(' && t>0){
                ans+='(';
                t++;
            }
            else if(s[i]==')' && t>1){
                ans+=')';
                t--;
            }
            else{
                t--;
            }
        }
        return ans;
    }
};