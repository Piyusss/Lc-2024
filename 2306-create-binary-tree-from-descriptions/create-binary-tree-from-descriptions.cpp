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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>childSet;

        for(auto it:descriptions){
            int par=it[0];
            int child=it[1];
            int dir=it[2];

            if(mp.find(par)==mp.end()){
                mp[par]=new TreeNode(par);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(dir==1){
                mp[par]->left=mp[child];
            }
            else{
                mp[par]->right=mp[child];
            }

            childSet.insert(child);
        }

        for(auto it:descriptions){
            int par=it[0];
            if(childSet.find(par)==childSet.end()){
                return mp[par];
            }
        }
        return NULL;
    }
};