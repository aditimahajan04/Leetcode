class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int maxSize = INT_MIN;
        map<string,int> mapp;

        for(int i=0;i<wordDict.size();i++){
            mapp[wordDict[i]]++;
            int curr_size = wordDict[i].size();
            maxSize = max(maxSize , curr_size);
        }
        vector<bool> arr(s.length()+1 , false);
        arr[0] = true; // cuz empty string is always present and true :
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=maxSize;j++){
                if(i-j >= 0){
                    string str = s.substr(i-j , j);
                    if(mapp.find(str) != mapp.end() && arr[i-j] == true){
                        arr[i] = true;
                        break;
                    }
                }
            }

        }
        return arr[n];
    }
};