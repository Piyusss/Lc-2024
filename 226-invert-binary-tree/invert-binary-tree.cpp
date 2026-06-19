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

    void f(TreeNode* &node){
        if(node==NULL) return;

        TreeNode* temp=node->left;
        node->left=node->right;
        node->right=temp;

        f(node->left);
        f(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;

        f(root);
        return root;
    }
};