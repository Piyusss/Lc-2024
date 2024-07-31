class Solution {
public:

void dfs(int node,vector<int>adjList[],vector<int>adjListRev[],vector<int>& visited,int &cnt){
    visited[node]=1;

    for(auto &it:adjList[node]){
        //ja sakte hai to dikkt hai
        if(visited[it]==1)continue;
        cnt++;
        dfs(it,adjList,adjListRev,visited,cnt);
    }
    for(auto &it:adjListRev[node]){
        //dikkat nahi hai
        if(visited[it]==1)continue;
        dfs(it,adjList,adjListRev,visited,cnt);
    }
}
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<int>adjList[n];
        vector<int>adjListRev[n];

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adjList[u].push_back(v);
            adjListRev[v].push_back(u);
        }

        int cnt=0;
        vector<int>visited(n,0);
        dfs(0,adjList,adjListRev,visited,cnt);

        return cnt;
    }
};