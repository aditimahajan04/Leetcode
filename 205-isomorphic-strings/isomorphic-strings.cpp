class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> snap;
        unordered_map<char,bool> used;
        for(int i=0;i<s.length();i++){
            if(snap.count(s[i])){
                if(snap[s[i]] !=t[i]){
                    return false;
                }
            }
            else{
                if(used.count(t[i])){
                    return false;
                }
                snap[s[i]]=t[i];
                used[t[i]]=true;
            }
        }
        return true;
    }
};