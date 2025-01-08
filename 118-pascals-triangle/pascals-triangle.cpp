class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0){
            return {};
        }
        else if(numRows==1){
            return {{1}};
        }
        vector<vector<int>> result(numRows,vector<int>());

        result[0]={1};
        for(int i=1;i<numRows;++i){
            result[i].push_back(1);
        
        for(int j=1;j<i;++j){
            result[i].push_back(result[i-1][j-1]+result[i-1][j]);
        }
        result[i].push_back(1);
    }
    return result;
    }
};