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
TreeNode* f(TreeNode* node,int k){
    if(node==NULL)return NULL;
    if(node->val==k)return node;
    else if(node->val<k)return f(node->right,k);
    else return f(node->left,k);
}
    TreeNode* searchBST(TreeNode* root, int k) {
        return f(root,k);
    }
};