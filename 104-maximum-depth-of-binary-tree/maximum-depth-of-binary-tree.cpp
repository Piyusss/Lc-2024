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

void f (TreeNode* root,int cnt){
    if(root==NULL)return;

    maxi=max(maxi,cnt);
    f(root->left,cnt+1);
    f(root->right,cnt+1);
}
    int maxDepth(TreeNode* root) {
        f(root,1);
        return maxi;
    }
};