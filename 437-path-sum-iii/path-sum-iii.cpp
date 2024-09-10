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
ll ans;
ll t;

void f(TreeNode* &root,ll curSum){
    if(!root)return;

    curSum+=root->val;
    f(root->left,curSum);
    f(root->right,curSum);
    
    if(curSum==t)ans++;
}

void f2(TreeNode* &root){
    if(!root)return;
    f2(root->left);
    f2(root->right);
    f(root,(long long)0);
}
    int pathSum(TreeNode* root, int targetSum) {
        t=targetSum;
        f2(root);
        return ans;
    }
};