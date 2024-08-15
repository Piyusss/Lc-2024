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
TreeNode* f(TreeNode* &root){
    if(!root)return NULL;

    root->left=f(root->left);
    root->right=f(root->right);

    if(!root->left && !root->right && root->val==0)return NULL;
    return root;
}
    TreeNode* pruneTree(TreeNode* root) {
        return f(root);
    }
};