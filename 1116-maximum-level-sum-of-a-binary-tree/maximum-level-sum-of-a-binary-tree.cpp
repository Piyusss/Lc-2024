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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int ans=1;
        int maxi=INT_MIN;
        int lev=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            lev++;
            
            while(n--){
                auto it=q.front();
                q.pop();

                sum+=it->val;

                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }

            if(sum>maxi){
                maxi=sum;
                ans=lev;
            }
        }

        return ans;
    }
};