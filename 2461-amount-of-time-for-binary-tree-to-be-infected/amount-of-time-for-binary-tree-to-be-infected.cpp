class Solution {
public:
    unordered_map<int, vector<int>> graph;
    void f(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        f(root->left);
        f(root->right);
    }
        int amountOfTime(TreeNode* root, int start) {
        f(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        int mp=-1;
        while(!q.empty()) {
            ++mp;
            for (int i = q.size(); i > 0; --i) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for(int adjacentNode:graph[currentNode]) {
                    if(!visited.count(adjacentNode)){
                        q.push(adjacentNode);
                    }
                }
            }
        }
        return mp;
    }
};