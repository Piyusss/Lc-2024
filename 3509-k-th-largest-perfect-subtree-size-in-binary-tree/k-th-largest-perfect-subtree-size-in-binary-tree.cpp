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

vector<int>kthLargest;
unordered_set<TreeNode*>st;
int nice=0;

//n=(2^h+1)-1;

int f(TreeNode* root){
    if(!root) return 0;

    int l=f(root->left);
    int r=f(root->right);

    if(l==r){
        if(( root->left && st.find(root->left)!=st.end()) || ( root->right && st.find(root->right)!=st.end()) ) st.insert(root);
        else kthLargest.push_back(l+r+1);
    }
    else st.insert(root);

    
    return l+r+1;

}

    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        f(root);

        sort(kthLargest.begin(),kthLargest.end());
        reverse(kthLargest.begin(),kthLargest.end());

        for(auto &it:kthLargest)cout<<it<<" ";

        if(kthLargest.size()<k) return -1;

        return kthLargest[k-1];

    }
};