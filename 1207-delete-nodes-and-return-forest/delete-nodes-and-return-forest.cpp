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

TreeNode* f(TreeNode* root,vector<TreeNode*>& res,unordered_set<int>& st){
    if(root==NULL)return NULL;

    root->left=f(root->left,res,st);
    root->right=f(root->right,res,st);

    if(st.find(root->val)!=st.end()){
        if(root->left) res.push_back(root->left);
        if(root->right) res.push_back(root->right);
        return NULL;
    }
    else{
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;

        unordered_set<int>st;
        for(auto &it:to_delete)st.insert(it);

        f(root,res,st);

        if(st.find(root->val)==st.end())res.push_back(root);

        return res;
    }
};