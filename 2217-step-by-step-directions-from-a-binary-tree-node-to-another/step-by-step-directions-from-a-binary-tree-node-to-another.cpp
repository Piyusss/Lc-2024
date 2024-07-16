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

        string lcaToSrc="";
        string lcaToDest="";

        findPath(root,startValue,lcaToSrc);
        findPath(root,destValue,lcaToDest);

        cout<<lcaToSrc<<" "<<lcaToDest;

        int mark=-1;
        for(int i=0;i<lcaToSrc.size() && i<lcaToDest.size();i++){
            if(lcaToSrc[i]==lcaToDest[i])mark=i;
            else break;
        }

        string res="";
        for(int i=mark+1;i<lcaToSrc.size();i++)res+="U";

        for(int i=mark+1;i<lcaToDest.size();i++)res+=lcaToDest[i];

        return res;
    }
};