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

    pair<TreeNode*,int>f(TreeNode* u){
        if(!u) return {nullptr,0};

        auto L=f(u->left);
        auto R=f(u->right);

        if(L.second>R.second) return {L.first,L.second+1};
        if(R.second>L.second) return {R.first,R.second+1};

        return {u,L.second+1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return f(root).first;
    }
};