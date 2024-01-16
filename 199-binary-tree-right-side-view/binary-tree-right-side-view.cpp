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
void f(vector<int>&ans,TreeNode* node,int level){
    if(node==NULL)return;
    if(ans.size()==level)ans.push_back(node->val);

    f(ans,node->right,level+1);
    f(ans,node->left,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        f(ans,root,0);
        return ans;
    }
};