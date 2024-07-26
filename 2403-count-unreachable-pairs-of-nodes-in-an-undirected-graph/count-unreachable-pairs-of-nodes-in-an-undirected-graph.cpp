class Solution {
public:

void dfs(int node,vector<int>adjList[],vector<int>& vis,long long &flag){
    vis[node]=1;
    flag++;

    for(auto it:adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,vis,flag);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adjList[n];

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>vis(n,0);

        long long ans=0;
        long long remaining_nodes=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long flag=0;
                dfs(i,adjList,vis,flag);
                ans+= (flag*(remaining_nodes-flag));
                remaining_nodes-=flag;
            }
        }

        return ans;
    }
};