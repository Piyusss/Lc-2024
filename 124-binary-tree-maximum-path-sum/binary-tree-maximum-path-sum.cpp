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

int maxi=INT_MIN;


int f(TreeNode* node){
    if(node==NULL)return 0;

    int lh=f(node->left);
    int rh=f(node->right);

    int both=lh+rh+node->val;
    int alone=node->val;
    int elongate=max(lh,rh)+node->val;

    maxi=max({maxi,both,elongate,alone});
    return max(elongate,alone);
}
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxi;
    }
};