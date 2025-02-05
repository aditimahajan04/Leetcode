class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        int count=0;
        vector<int> arr;
        int i=0;
        while(i<s1.size()){
            if(s1[i]==s2[i]){
                i++;
            }
            else{
                count++;
                if(count<=2){
                    arr.push_back(i);
                }
                else{
                    count--;
                    return false;
                }
                i++;
            }
        }
        if(count==2){
            swap(s2[arr[0]],s2[arr[1]]);
        }
        if(s1==s2){
            return true;
        }
        else{
            return false;
        }
    }
};