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

TreeNode* f(TreeNode* root, int p, int q){
    if(root==NULL || root->val==p || root->val==q)return root;

    TreeNode* lh=f(root->left,p,q);
    TreeNode* rh=f(root->right,p,q);

    if(lh!=NULL && rh!=NULL)return root;
    else if(lh!=NULL)return lh;
    else return rh;
}

bool findPath(TreeNode* lca,int target,string &path){
    if(!lca)return 0;

    if(lca->val==target)return 1;

    path+="L";
    if(findPath(lca->left,target,path))return 1;
    path.pop_back();

    path+="R";
    if(findPath(lca->right,target,path))return 1;
    path.pop_back();

    return 0;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=f(root,startValue,destValue);

        string lcaToSrc="";
        string lcaToDest="";

        findPath(lca,startValue,lcaToSrc);
        findPath(lca,destValue,lcaToDest);

        string res="";
        for(int i=0;i<lcaToSrc.size();i++)res+="U";

        res+=lcaToDest;

        return res;
    }
};