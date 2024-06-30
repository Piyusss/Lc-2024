class Solution {
public:
vector<int>ans;
bool dfs(int node , vector<int>&vis , vector<int>&pathVis , vector<int>adj[],vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj,check))return 1;
            }
            else if(pathVis[it])return 1;
        }
        pathVis[node]=0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>adjList[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adjList[i].push_back(graph[i][j]);
            }
        }
        vector<int>vis(n),pathVis(n),temp(n),check(n);
        for(int i=0 ; i<n ; i++){
            vis=pathVis=temp;
            if( !dfs(i,vis,pathVis,adjList,check) ){
                ans.push_back(i);
            }
        }

        return ans;
    }
};