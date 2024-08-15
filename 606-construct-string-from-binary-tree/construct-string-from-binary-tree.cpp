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
string f(TreeNode* root){
    if(!root)return "";

    string stand=to_string(root->val);
    string left=f(root->left);
    string right=f(root->right);

    if(root->left && root->right)return stand + "(" + left + ")" + "(" + right + ")";
    if(root->left)return stand + "(" + left + ")";
    if(root->right)return stand + "(" + ")" + "(" + right + ")";
    return stand;
}
    string tree2str(TreeNode* root) {
        return f(root);
    }
};