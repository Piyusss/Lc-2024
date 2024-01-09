class Solution {
public:
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<vector<int>>&ans,vector<int>&temp,int n){
    vis[node]=1;
    temp.push_back(node);
    if(node==n-1){
        ans.push_back(temp);
    }

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans,temp,n);
        }
    }
    temp.pop_back();
    vis[node]=0;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        //now
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0,adj,vis,ans,temp,n);
        return ans;
    }
};