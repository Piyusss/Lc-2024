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
#define ll long long
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);

        vector<ll>v;
        while(!q.empty()){
            ll n=q.size();
            ll sum=0;
            
            while(n--){
                auto it=q.front();
                q.pop();

                sum+=it->val;

                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }

            v.push_back(sum);
        }

        sort(v.begin(),v.end());
        ll n=v.size();
        if((n-k)>=0 && (n-k)<=n-1) return v[n-k];
        return -1;
    }
};