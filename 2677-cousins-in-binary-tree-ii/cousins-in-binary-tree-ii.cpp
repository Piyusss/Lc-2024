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
    TreeNode* replaceValueInTree(TreeNode* root){
        vector<int>levelSum;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            int curLevelSum=0;
            while(n--){
                auto it=q.front();
                q.pop();

                curLevelSum += it->val;

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);

            }
            cout<<curLevelSum<<" ";
            levelSum.push_back(curLevelSum);
        }
        

        root->val=0;
        q.push(root);
        int idx=1;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();

                int siblingSum=(it->left ? it->left->val : 0) + (it->right ? it->right->val : 0) ;
                if(it->left){
                    it->left->val = levelSum[idx]-siblingSum;
                    if(it->left) q.push(it->left);
                }
                if(it->right){
                    it->right->val = levelSum[idx]-siblingSum;
                    if(it->right) q.push(it->right);
                }

            }
            idx++;
        }

        return root;

    }
};