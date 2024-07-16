class Solution {
public:

vector<int>adjList[1000+1];


void dfs(int node,vector<int>& vis,int ori,vector<vector<int>>& ans){
    vis[node]=1;

    for(auto &it:adjList[node]){
        if(!vis[it]){
            ans[it].push_back(ori);
            dfs(it,vis,ori,ans);
        }
    }
}


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        for(auto &it:edges){
            adjList[it[0]].push_back(it[1]);
        }

        vector<int>vis(n),vis2(n);
        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,i,ans);
                vis=vis2;
            }
        }

        return ans;

    }
};