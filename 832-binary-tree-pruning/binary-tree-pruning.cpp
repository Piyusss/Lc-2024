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
bool check(TreeNode* root){
    if(!root)return 0;

    if(root->val==1)return 1;
    if(check(root->left))return 1;
    if(check(root->right))return 1;
    return 0;
}
TreeNode* f(TreeNode* &root){
    if(!root)return NULL;

    if(!check(root->left))root->left=NULL;
    if(!check(root->right))root->right=NULL;

    f(root->left);
    f(root->right);

    return root;
}
    TreeNode* pruneTree(TreeNode* root) {
        f(root);
        if(!root->left && !root->right && root->val==0)return NULL;
        return root;
    }
};