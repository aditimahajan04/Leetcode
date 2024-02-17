class Solution {
public:
int searchInsert(vector<int>& nums, int target) {

    int s = 0 ; int e = nums.size()-1 ; int m = s+(e-s)/2 ; 
    while(s<=e){
   if(nums[m]==target){
       return m;
   }
     if(nums[m]>target){
        e = m-1 ; }   
    else s = m+1 ;
        m = s+(e-s)/2;
}
    return s;
}
    
};