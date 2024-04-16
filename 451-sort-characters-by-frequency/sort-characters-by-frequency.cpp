class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256);
        for(const char &ch : s){
            ++freq[ch];
        }

        vector<vector<int>> bucket(s.length()+1);
        for(int i=255;i>=0;--i){
            if(freq[i]){
                bucket[freq[i]].push_back(static_cast<char>(i));
            }
        }
        string sorted;
        for(int freq=s.length();freq>=0;--freq){
            for(const char &ch: bucket[freq]){
                sorted+=string(freq,ch);
            }
        }
        return sorted;
    }
};