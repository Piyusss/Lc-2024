class Solution {
public:
    int ans=INT_MIN;
    void fd(TreeNode* root,vector<int>&parent){
        if(!root)return;
        for(auto x:parent){
            ans=max(ans,abs(root->val-x));
        }
        parent.push_back(root->val);
        fd(root->left,parent);
        fd(root->right,parent);
        parent.pop_back();
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
              return INT_MIN;
        vector<int>temp;
        fd(root,temp);
        return ans;
    }
};