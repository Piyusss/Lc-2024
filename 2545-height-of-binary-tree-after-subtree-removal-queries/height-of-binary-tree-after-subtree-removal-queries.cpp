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
#include<bits/stdc++.h>
 
class Solution {
public:

int levelOfNode[100001];
int heightOfNode[100001];
int maxHeightOfLevel[100001];
int secondMaxHeightOfLevel[100001];


int f(TreeNode* root,int level){
    if(!root) return 0;

    levelOfNode[root->val]=level;
    int l=f(root->left,level+1);
    int r=f(root->right,level+1);

    heightOfNode[root->val]=max(l,r)+1;

    if(maxHeightOfLevel[level] < heightOfNode[root->val]){
        secondMaxHeightOfLevel[level]=maxHeightOfLevel[level];
        maxHeightOfLevel[level]=heightOfNode[root->val];
    }
    else if(secondMaxHeightOfLevel[level] < heightOfNode[root->val]){
        secondMaxHeightOfLevel[level]=heightOfNode[root->val];
    }
    return max(l,r) + 1;
}
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        f(root,0);

        vector<int>res;
        for(auto &it:queries){
            int value= levelOfNode[it] + (heightOfNode[it]==maxHeightOfLevel[levelOfNode[it]] ? 
            secondMaxHeightOfLevel[levelOfNode[it]] : maxHeightOfLevel[levelOfNode[it]]) -1 ;
            res.push_back(value);
        }

        return res;

    }
};