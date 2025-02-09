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

const int MAXN=1E5;
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

vector<ll>eulerTour;
int inTime[MAXN+1],outTime[MAXN+1],height[MAXN+1];
vector<int>res;
int cnt=1;

void eulerDfs(TreeNode* root){
    inTime[root->val] = cnt++;
    eulerTour.push_back(height[root->val]);

    if(root->left) eulerDfs(root->left);
    if(root->right) eulerDfs(root->right);

    outTime[root->val] = cnt++;
    eulerTour.push_back(height[root->val]);
}

void heightDfs(TreeNode* root){

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
        heightDfs(root);

        eulerTour.push_back(-1);
        eulerDfs(root);

        SegmentTree t(eulerTour);
        for(auto &c:queries){
            res.push_back(max(t.query(1,inTime[c]-1),t.query(outTime[c]+1,cnt-1)));
        }

        return res;
    }
};