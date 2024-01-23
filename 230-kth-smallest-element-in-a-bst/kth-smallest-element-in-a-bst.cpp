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

    f(ans,root->left);
    ans.push_back(root->val);
    f(ans,root->right);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        f(ans,root);
        return ans[k-1];
    }
};