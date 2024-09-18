class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end());
        int res = 1;
        vector<int> ans(2);
        ans = points[0];
        for(int i=1; i<points.size(); i++){
            if(ans[1] >= points[i][0]){
                ans[0] = points[i][0];
                ans[1] = min(ans[1], points[i][1]);
            }
            else{
                ans = points[i];
                res++;
            } 
        }
        return res;
    }
};