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
bool f(TreeNode*root1,TreeNode* root2){
    if(!root1 && !root2) return 1;
    if(!root1 || !root2) return 0;

    return ( (root1->val==root2->val) && ( (f(root1->left,root2->left) && f(root1->right,root2->right)) || 
                                           (f(root1->left,root2->right) && f(root1->right,root2->left)) ) ) ;
}
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};