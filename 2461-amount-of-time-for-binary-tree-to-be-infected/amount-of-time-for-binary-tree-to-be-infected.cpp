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

void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();

        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}

TreeNode* target=new TreeNode(-1);

void f(TreeNode* root,int start){
    if(root==NULL)return;

    if(root->val==start){
        target=root;
        return;
    }
    f(root->left,start);
    f(root->right,start);
}

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,parent_track);
        
        f(root,start);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=1;
        int cur_level=-1;
        int time=0;

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=1;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=1;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=1;
                }
            }
            time++;
        }


        return time-1;
    }
};