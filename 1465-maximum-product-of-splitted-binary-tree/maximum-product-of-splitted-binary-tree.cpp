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

#define ll long long
ll res=0;
ll totSum=0;
ll M=1E9+7;

void findTotSum(TreeNode* root){
    if(!root)return;

    totSum+=root->val;
    findTotSum(root->left);
    findTotSum(root->right);
}

ll f(TreeNode* root){
    if(!root)return 0;

    ll l=f(root->left);
    ll r=f(root->right);
    ll curSum=root->val + l + r ;

    res=max(res,((curSum)*(totSum-curSum)));

    return curSum;
}
    int maxProduct(TreeNode* root){
        findTotSum(root);
        f(root);
        return res%M;
    }
};