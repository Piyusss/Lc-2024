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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
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
            if(flag==0){
                ans.push_back(temp);
                flag=1;
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                flag=0;
            }
        }
        return ans;
    }
};