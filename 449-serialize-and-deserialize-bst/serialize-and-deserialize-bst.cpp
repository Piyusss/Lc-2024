/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

TreeNode* ff(vector<int>&nums,int &idx,int bound){
    if(idx==nums.size() || nums[idx]>bound)return NULL;

    TreeNode* root=new TreeNode(nums[idx++]);
    root->left=ff(nums,idx,root->val);
    root->right=ff(nums,idx,bound);

    return root;
}


string ans;
vector<string>store;

void f(TreeNode* &root){
    if(!root)return;
    store.push_back(to_string(root->val));
    f(root->left);
    f(root->right);
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans="";
        f(root);
        for(auto &it:store){
            ans+=it;
            ans+=",";
        }
        cout<<ans.substr(0,ans.size()-1);
        cout<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>v;
        //
        vector<string>temp;
        string flag="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                temp.push_back(flag);
                flag="";
                continue;
            }
            flag+=data[i];
        }
        for(auto &it:temp)v.push_back(stoi(it));
        //
        int i=0;
        return ff(v,i,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;