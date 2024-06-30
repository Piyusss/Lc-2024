class Solution {
public:
bool dfs(int node,vector<int>& vis,vector<int>adjList[],
vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;

    for(auto it:adjList[node]){
        if(!vis[it]){
            if(dfs(it,vis,adjList,pathVis))return 1;
        }
        else{
            if(pathVis[it])return 1;
        }
    }

    pathVis[node]=0;
    return 0;
}
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adjList[n];
        
        for(auto it:pre){
            adjList[it[1]].push_back(it[0]);
        }

        vector<int>vis(n),pathVis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,adjList,pathVis))return 0;
            }
        }

        return 1;
    }
};