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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>>ans;
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
        //now
        int cnt=0;
        for(auto it:ans){
            vector<int>temp;
            for(auto it2:it){
                temp.push_back(it2);
            }
            if(cnt&1){
                for(int i=0;i<temp.size();i++){
                    if((temp[i]&1))return 0;
                }
                for(int i=0;i<temp.size()-1;i++){
                    if(temp[i+1]>=temp[i])return 0;
                }
            }
            else{
                for(int i=0;i<temp.size();i++){
                    if(!(temp[i]&1))return 0;
                }
                for(int i=0;i<temp.size()-1;i++){
                    if(temp[i+1]<=temp[i])return 0;
                }
            }
            cnt++;
        }
        return 1;
    }
};