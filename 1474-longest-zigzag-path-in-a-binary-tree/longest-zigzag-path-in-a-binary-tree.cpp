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

void f(TreeNode* root,int steps,bool toLeft){
    if(!root)return;
    maxi=max(maxi,steps);

    if(toLeft){
        f(root->left,steps+1,0);
        f(root->right,1,1);
    }
    else{
        f(root->right,steps+1,1);
        f(root->left,1,0);
    }
}
    int longestZigZag(TreeNode* root) {
        f(root,0,0);
        f(root,0,1);
        return maxi;
    }
};