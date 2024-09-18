class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char,int> mp;

        for(int i = 0;i<s.size();i++)
        mp[s[i]] = i;

        int start = 0,end = -1;
        for(int i = 0;i<s.size();i++)
        {
            end = max(end,mp[s[i]]);
            if(end==i)
            {
                ans.push_back(end-start+1);
                end = -1;
                start = i+1;
            }
        }
        return ans; 
    }
};