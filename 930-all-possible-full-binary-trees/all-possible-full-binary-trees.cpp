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
vector<TreeNode*> f(int n){
    if(n%2==0)return {};
    if(n==1)return {new TreeNode(0)};
    
    vector<TreeNode*>res;
    for(int i=1;i<=n-1;i+=2){
        vector<TreeNode*> leftBST=f(i);
        vector<TreeNode*> rightBST=f(n-i-1);

        for(auto &l:leftBST){
            for(auto &r:rightBST){
                TreeNode* root=new TreeNode(0);
                root->left=l;
                root->right=r;
                res.push_back(root);
            }
        }
    }

    return res;
}
    vector<TreeNode*> allPossibleFBT(int n) {
        return f(n);
    }
};