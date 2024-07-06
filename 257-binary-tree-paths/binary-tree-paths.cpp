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
vector<vector<int>>ans;

void f(TreeNode* root,vector<int>temp){
    if(root==NULL)return;
    
    temp.push_back(root->val);
    f(root->left,temp);
    f(root->right,temp);

    if(root->left==NULL && root->right==NULL)ans.push_back(temp);

}
    vector<string> binaryTreePaths(TreeNode* root){
        vector<int>temp;
        f(root,temp);

        vector<string>fin;
        for(auto it:ans){
            string t="";
            for(auto it2:it){
                t+=to_string(it2);t+="->";
            }
            t.pop_back();t.pop_back();
            fin.push_back(t);
        }
        return fin;
    }
};