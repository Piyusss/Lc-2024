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

vector<int> pick_front(vector<int>& nums,int idx){
    vector<int>temp;
    for(int i=0;i<=idx;i++)temp.push_back(nums[i]);
    return temp;
}
vector<int> pick_back(vector<int>& nums,int idx){
    vector<int>temp;
    for(int i=idx;i<nums.size();i++)temp.push_back(nums[i]);
    return temp;
}
TreeNode* f(vector<int>& nums){
        int n=nums.size();
        int slow=nums[n/2];
        int prevSlow=nums[(n/2)-1];
        
        vector<int>fro=pick_front(nums,(n/2)-1);
        vector<int>bac=pick_back(nums,(n/2)+1);
        TreeNode* root=new TreeNode(slow);

        root->left=sortedArrayToBST(fro);
        root->right=sortedArrayToBST(bac);
        
        return root;
}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return NULL;
        if(n==1)return new TreeNode(nums[0]);

        return f(nums);
    }
};