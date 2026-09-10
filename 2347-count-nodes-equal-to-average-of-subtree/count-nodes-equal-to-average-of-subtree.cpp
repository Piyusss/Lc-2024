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

    int ans;
    pair<int,int> f(TreeNode* root){
        if(!root)return {0,0};

        auto p1=f(root->left);
        auto p2=f(root->right);

        int totSum=root->val + p1.first + p2.first;
        int totCnt=1 + p1.second + p2.second;

        if(totSum/totCnt==root->val)ans++;

        return {totSum,totCnt};
    }

    int averageOfSubtree(TreeNode* root) {
        ans=0;
        f(root);
        return ans;
    }
};