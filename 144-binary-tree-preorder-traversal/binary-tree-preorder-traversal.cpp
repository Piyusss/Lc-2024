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
void f(vector<int>&ans,TreeNode* root){
    if(root==NULL)return;

    ans.push_back(root->val);
    f(ans,root->left);
    f(ans,root->right);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        f(ans,root);
        return ans;
    }
};