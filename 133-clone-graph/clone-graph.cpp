/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

unordered_map<Node*,Node*>mp;

void dfs(Node* node, Node* first_clone_node){
    for(Node* it:node->neighbors){
        if(mp.find(it)==mp.end()){
            Node* clone=new Node(it->val);
            mp[it]=clone;
            first_clone_node->neighbors.push_back(clone);
            dfs(it,clone);
        }
        else{
            first_clone_node->neighbors.push_back(mp[it]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;

        Node* first_clone_node=new Node(node->val);
        mp[node]=first_clone_node;

        dfs(node,first_clone_node);

        return first_clone_node;
    }
};