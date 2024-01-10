class Solution {
public:
void dfs(int node,vector<pair<int,int>>adj[],vector<int>&vis,int &mini){
    vis[node]=1;
    for(auto it:adj[node]){
        mini=min(mini,it.second);
        if(!vis[it.first]){
            dfs(it.first,adj,vis,mini);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //now
        int mini=INT_MAX;
        vector<int>vis(n+1,0);
        dfs(1,adj,vis,mini);
        return mini;
    }
};