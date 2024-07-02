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
    if(root==NULL)return 0;

    int lh=f(root->left);
    int rh=f(root->right);
    if(lh && rh)return 1+min(lh,rh);
    return 1+max(lh,rh);
}
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return f(root);
    }
};