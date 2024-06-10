/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return {};
        stack<pair<TreeNode *,bool>>st;
        vector<int>ans;
        st.push({root,false});
        while(!st.empty()){
            TreeNode *node=st.top().first;
            bool vis=st.top().second;
            st.pop();
            if(vis==false){
                 st.push({node,true});
            if(node->right!=nullptr)st.push({node->right,false});
           
            if(node->left!=nullptr)st.push({node->left,false});
            }else{
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};