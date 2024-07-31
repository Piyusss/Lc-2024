class Solution {
public:
vector<int> f (int src,vector<pair<int,int>> adjList[],int n){
    priority_queue<  pair<int,int>,  vector<pair<int,int>>  ,greater<pair<int,int>>  >pq;
    pq.push({0,src});

    vector<int>dis(n,1e9);
    dis[src]=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int d=it.first;
        int node=it.second;

        for(auto &it2:adjList[node]){
            int adjNode=it2.first;
            int path_len=it2.second;
            if(d+path_len < dis[adjNode]){
                dis[adjNode]=d+path_len;
                pq.push({d+path_len,adjNode});
            }
        }
    }

    return dis;
}
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adjList[n];

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        vector<int>dij_from_front=f(0,adjList,n);
        vector<int>dij_from_back=f(n-1,adjList,n);

        vector<bool>res(edges.size(),false);
        int i=0;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(dij_from_front[u] + w + dij_from_back[v]==dij_from_front[n-1])res[i]=true;
            u=u^v;v=v^u;u=u^v;
            if(dij_from_front[u] + w + dij_from_back[v]==dij_from_front[n-1])res[i]=true;

            i++;
        }

        return res;
    }
};