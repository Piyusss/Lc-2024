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

vector<TreeNode*> f(int start,int end){
    if(start>end)return {NULL};
    if(start==end)return {new TreeNode(start)};
    
    vector<TreeNode*>res;
    for(int root=start;root<=end;root++){//possible roots
        vector<TreeNode*> leftBST=f(start,root-1);
        vector<TreeNode*> rightBST=f(root+1,end);

        for(auto &l:leftBST){
            for(auto &r:rightBST){
                TreeNode* rt=new TreeNode(root);
                rt->left=l;
                rt->right=r;
                res.push_back(rt);
            }
        }
    }

    return res;
}
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};