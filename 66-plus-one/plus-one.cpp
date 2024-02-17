class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {

        for(int j=digits.size()-1;j>=0;j--){
           if(digits[j]<9){
               digits[j]++;
               return digits;
           }
            digits[j]=0;
        }
        vector<int>num;
        num.push_back(1);

        for(int i =0;i<digits.size();i++)
        {
        num.push_back(digits[i]);
        }
        return num;
    
    }
};