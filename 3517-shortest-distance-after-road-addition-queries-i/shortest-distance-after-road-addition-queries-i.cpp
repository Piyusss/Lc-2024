class Solution {
public:

 int dijkstra(const vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0]=0;
        pq.push({0,0}); 
        while (!pq.empty()) {
            auto it = pq.top();
            int d=it.first;
            int u=it.second;
            pq.pop();
            if (d>dist[u]) continue;
            for (auto& it : adj[u]) {
                int v=it.first;
                int w=it.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }

        return dist[n-1];

}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q){
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<n-1;i++)graph[i].push_back({i+1,1}); 

        vector<int>res;
        for(auto& query:q) {
            int u=query[0],v=query[1];
            graph[u].push_back({v,1});
            res.push_back(dijkstra(graph,n));
        }
        
        return res;
    }
};