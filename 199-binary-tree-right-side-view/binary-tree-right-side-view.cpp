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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>fin;
        if(root==NULL)return fin;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
        for(auto it:ans){
            fin.push_back(it[it.size()-1]);
        }
        return fin;
    }
};