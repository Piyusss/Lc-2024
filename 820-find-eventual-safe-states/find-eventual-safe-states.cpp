class Solution {
public:
bool dfs(int node , vector<int>&vis , vector<int>&pathVis , vector<int>adj[],vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj,check)){
                    check[node]=1;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=1;
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>adj[V+5];
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>vis(V+5,0);
        vector<int>pathVis(V+5,0);
        vector<int>ans;
        vector<int>check(V+5,0);
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adj,check);
            }
        }
        for(int i=0 ; i<V ; i++){
            if(check[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};