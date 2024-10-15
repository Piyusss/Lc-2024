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

vector<int>ans;
vector<pair<int,int>>res;
unordered_map<int,int>mp;

int f(TreeNode* root){
    if(!root) return 0;

    int l=f(root->left);
    int r=f(root->right);

    mp[l+r+root->val]++;

    return l+r+root->val;

}

static bool comp(pair<int,int>a,pair<int,int>b){
    return a.second > b.second;
}

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left && !root->right) return {root->val};

        f(root);

        for(auto &it:mp) res.push_back({it.first,it.second});
        sort(res.begin(),res.end(),comp);

        ans.push_back(res[0].first);

        for(int i=1;i<res.size();i++){
            if(res[i].second==res[0].second)ans.push_back(res[i].first);
            else break;
        }

        return ans;

    }
};