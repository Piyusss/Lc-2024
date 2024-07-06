/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL || root==p || root==q)return root;

    TreeNode* lh=f(root->left,p,q);
    TreeNode* rh=f(root->right,p,q);

    if(lh!=NULL && rh!=NULL)return root;
    else if(lh!=NULL)return lh;
    else return rh;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};