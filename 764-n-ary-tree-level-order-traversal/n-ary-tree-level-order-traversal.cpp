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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();

            vector<int>temp;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                temp.push_back(node->val);

                q.pop();

                for(auto &it:node->children)q.push(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};