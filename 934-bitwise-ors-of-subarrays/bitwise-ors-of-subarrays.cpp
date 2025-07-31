class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> cur;
        unordered_set<int> prev;

        for(int num:arr){
            cur.clear();
            cur.insert(num);

            for(int x: prev){
                cur.insert(x|num);
            }
            for(int val: cur){
                result.insert(val);
            }
            prev=cur;
        }
        return result.size();
    }
};