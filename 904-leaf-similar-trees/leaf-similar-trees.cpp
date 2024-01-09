class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*,vector<int>&)> f =
            [&](TreeNode* root, vector<int>& lv) {
                if(!root) return;
                if(!root->left && !root->right)lv.push_back(root->val);
                f(root->left,lv);
                f(root->right,lv);
            };
        vector<int>v1, v2;
        f(root1,v1);
        f(root2,v2);
        return v1==v2;
    }
};