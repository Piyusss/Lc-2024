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

int f(TreeNode* root,int prevNodeVal){
    if(!root)return 0;

    int l=f(root->left,root->val);
    int r=f(root->right,root->val);

    maxi=max(maxi,l+r);

    if(root->val==prevNodeVal)return max(l,r)+1;
    return 0;

    
}
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        f(root,root->val);
        return maxi;
    }
};