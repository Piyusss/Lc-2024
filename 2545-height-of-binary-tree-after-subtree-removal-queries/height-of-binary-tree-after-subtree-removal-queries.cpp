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
using ll=long long;

class SegmentTree
{
private:
    vector<ll> tree;
    vector<ll> arr;
    ll n;
 
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1] , tree[2 * node + 2]);
        }
    }
 
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (r < start || l > end)
        {
            return INT_MIN;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll left = query(2 * node + 1, start, mid, l, r);
        ll right = query(2 * node + 2, mid + 1, end, l, r);
        return max(left , right);
    }
 
public:
    SegmentTree(const vector<ll> &input)
    {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }
 
    ll query(ll l, ll r)
    {
        return query(0, 0, n - 1, l, r);
    }
};



class Solution {
public:

vector<ll>eulerTour,heightsTour;
int inTime[100000+1];
int outTime[100000+1];
int height[100000+1];
vector<int>res;
int cnt=1;
int tot=0;

void dfs(TreeNode* root){
    inTime[root->val] = cnt++;
    eulerTour.push_back(root->val);

    if(root->left) dfs(root->left);
    if(root->right) dfs(root->right);

    outTime[root->val] = cnt ++;
    eulerTour.push_back(root->val);
}

void heightDfs(TreeNode* root){
    tot++;

    if(root->left){
        height[root->left->val] = height[root->val]+1;
        heightDfs(root->left);
    }
    if(root->right){
        height[root->right->val] = height[root->val]+1;
        heightDfs(root->right);
    }

}

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // memset(height,0,sizeof(height));
        heightDfs(root);

        // for(int i=1;i<=tot;i++) cout<<height[i]<<" ";
        // cout<<"\n";

        eulerTour.push_back(-1);
        heightsTour.push_back(-1);
        dfs(root);
        int s=eulerTour.size();
        for(int i=1;i<s;i++){
            // cout<<eulerTour[i]<<" ";
            heightsTour.push_back(height[eulerTour[i]]);
        }
        // cout<<"\n";
        // for(int i=1;i<s;i++){
        //     cout<<height[i]<<" ";
        // }
        // cout<<"\n"<<"\n";
        SegmentTree t(heightsTour);

        for(auto &c:queries){
            int leftIdx=inTime[c];
            int rightIdx=outTime[c];
            // cout<<leftIdx<<" "<<rightIdx<<"\n";
            int a=t.query(1,leftIdx-1);
            int b=t.query(rightIdx+1,s-1);
            // cout<<a<<" "<<b<<"\n"<<"\n";
            res.push_back(max(a,b));
        }

        return res;
    }
};