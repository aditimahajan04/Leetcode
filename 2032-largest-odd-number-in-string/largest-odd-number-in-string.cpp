class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string odd="";
        for(int i=n-1;i>=0;i--){
            if(num[i] %2 ==1){
                odd+=num.substr(0,i+1);
                break;
            }
        }
        return odd;
    }
};

