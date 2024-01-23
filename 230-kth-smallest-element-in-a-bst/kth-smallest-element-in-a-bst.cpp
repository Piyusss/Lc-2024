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
int cnt=0;int ans=0;
void f(TreeNode* root,int k){
    if(root==NULL)return;

    f(root->left,k);
    cnt++;
    if(cnt==k){
        ans=root->val;
        return;
    }
    f(root->right,k);
}
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return ans;
    }
};