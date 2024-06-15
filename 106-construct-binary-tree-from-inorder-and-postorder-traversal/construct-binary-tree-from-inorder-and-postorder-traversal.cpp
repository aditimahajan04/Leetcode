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
TreeNode* solve(vector<int>& postorder, int &postIndex, int start, int end, unordered_map<int,int>& m)
    {
       //base case
        if(postIndex < 0 || start > end)
         return NULL;

        int element = postorder[postIndex--];
        int pos = m[element];

        //make current root node
        TreeNode* root = new TreeNode(element);
        //make right sub-tree
        root->right = solve(postorder, postIndex, pos+1, end,  m);
        //make left sub-tree
        root->left = solve(postorder, postIndex, start, pos-1,  m);
        return root;
     }
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size()-1;
        unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++) {
            m[inorder[i]] = i; 
        }
     return solve(postorder, size, 0, size,  m);
    }
};