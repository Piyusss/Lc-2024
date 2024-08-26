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

    for(auto &it:root->children)f(ans,it);
    ans.push_back(root->val);
}
    vector<int> postorder(Node* root){
        vector<int>ans;
        f(ans,root);
        return ans;
    }
};