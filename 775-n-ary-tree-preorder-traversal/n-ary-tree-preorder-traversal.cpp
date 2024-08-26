/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(vector<int>&ans,Node* root){
    if(root==NULL)return;
    
    ans.push_back(root->val);
    for(auto &it:root->children)f(ans,it);
}
    vector<int> preorder(Node* root) {
        vector<int>ans;
        f(ans,root);
        return ans;
    }
};