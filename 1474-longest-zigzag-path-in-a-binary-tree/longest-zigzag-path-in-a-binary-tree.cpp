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

int maxi=0;

void f(TreeNode* root,int l,int r){
    if(!root)return;
    maxi=max(maxi,max(l,r));

    f(root->left,r+1,0);
    f(root->right,0,l+1);
}
    int longestZigZag(TreeNode* root) {
        f(root,0,0);
        return maxi;
    }
};