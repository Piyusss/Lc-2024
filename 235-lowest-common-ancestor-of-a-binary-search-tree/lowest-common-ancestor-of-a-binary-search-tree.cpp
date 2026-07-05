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

    TreeNode* f(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==NULL || node==p || node==q) return node;

        TreeNode* lh=f(node->left,p,q);
        TreeNode* rh=f(node->right,p,q);

        if(lh && rh) return node;
        return lh?lh:rh;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};