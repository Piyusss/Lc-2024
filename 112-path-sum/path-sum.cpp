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
bool f(TreeNode* root,int target,int curSum){
    if(root==NULL)return 0;

    curSum+=root->val;

    if((root->left==NULL && root->right==NULL && curSum==target)
    || (f(root->left,target,curSum) || f(root->right,target,curSum)) )return 1;

    return 0;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;

        return f(root,targetSum,0);
    }
};