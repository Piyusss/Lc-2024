class Solution {
public:
    int cnt=0;

    void dfs(int node,vector<int>adjList[],unordered_set<int>& st,vector<int>& vis){
        vis[node]=1;
        cnt++;

        for(auto &it:adjList[node]){
            if( st.count(it)==0 && !vis[it] ){
                dfs(it,adjList,st,vis);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adjList[n];

        unordered_set<int>st(restricted.begin(),restricted.end());

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>vis(n,0);

        dfs(0,adjList,st,vis);

        return cnt;
    }
};