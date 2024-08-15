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
int f(TreeNode* root){
    if(!root)return 0;
    return 1+f(root->left)+f(root->right);
}

bool dfs(int idx,TreeNode* root,int tot){
    if(!root)return 1;
    if(idx>tot)return 0;
    return dfs(2*idx,root->left,tot) && dfs(2*idx+1,root->right,tot);
}
    bool isCompleteTree(TreeNode* root) {
        int tot=f(root);
        if(!dfs(1,root,tot))return 0;
        return 1;
    }
};