class Solution {
public:
    int maxRec(vector<int> &v){
        int res=0;
        stack<pair<int,int>> st;
        for(int i=0;i<v.size();i++){
            int cnt=1;
            while(!st.empty() && st.top().first>v[i]){
                cnt+=st.top().second;
                res=max(res,st.top().first*(cnt-1));
                st.pop();
            }
            st.push({v[i],cnt});
        }
        int cnt=1;
        while(!st.empty()){
            cnt+=st.top().second;
            res=max(res,st.top().first*(cnt-1));
            st.pop();
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int res=0;
        vector<int> v(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]++;
                }
            }
            res=max(res,maxRec(v));
        }
        return res;
    }
};