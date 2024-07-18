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

void form_graph(TreeNode* root,TreeNode* prev_node,unordered_set<TreeNode*>& leaf_nodes,
    unordered_map<TreeNode*,vector<TreeNode*>>& adjList){
    if(root==NULL)return;

    if(root->left==NULL && root->right==NULL)leaf_nodes.insert(root);

    if(prev_node){
        adjList[root].push_back(prev_node);
        adjList[prev_node].push_back(root);
    }

    form_graph(root->left,root,leaf_nodes,adjList);
    form_graph(root->right,root,leaf_nodes,adjList);
}
    int countPairs(TreeNode* root, int maxLevel){
        unordered_set<TreeNode*>leaf_nodes;
        unordered_map<TreeNode*,vector<TreeNode*>>adjList;
        form_graph(root,NULL,leaf_nodes,adjList);

        int cnt=0;

        for(auto &it:leaf_nodes){
            queue<TreeNode*>q;
            q.push(it);

            unordered_set<TreeNode*>vis;
            vis.insert(it);

            for(int level=0;level<=maxLevel;level++){
                int n=q.size();
                while(n--){
                    auto front_node=q.front();
                    q.pop();

                    if(front_node!=it && leaf_nodes.count(front_node))cnt++;

                    for(auto &neg:adjList[front_node]){
                        if(!vis.count(neg)){
                            vis.insert(neg);
                            q.push(neg);
                        }
                    }
                }
            }
        }

        return cnt/2;
    }
};