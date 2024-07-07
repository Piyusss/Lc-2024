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

        queue<pair<int,int>> q; q.push({start,0});
        unordered_set<int> visited; visited.insert(start);

        int maxi=0;
        while(!q.empty()) {
                int currentNode = q.front().first;
                int step=q.front().second;
                q.pop();

                maxi=max(maxi,step);

                for(int adjacentNode:graph[currentNode]) {
                    if(!visited.count(adjacentNode)){
                        visited.insert(currentNode);
                        q.push({adjacentNode,step+1});
                    }
                }
        }
        return maxi;
    }
};