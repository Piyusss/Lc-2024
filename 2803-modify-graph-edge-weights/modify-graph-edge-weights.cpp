class Solution {
public:

#define ll long long

ll f(ll n,vector<pair<ll,ll>>adjList[],ll src,ll dest) {
    vector<ll>dis(n,INT_MAX);
    dis[src]=0;
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({src, 0});

    while(!pq.empty()){
        ll node=pq.top().first;
        ll dist=pq.top().second;

        pq.pop();
        
        for(auto &neighbor:adjList[node]){
            ll adjNode=neighbor.first;
            ll adjWt=neighbor.second;

            if(dis[node] + adjWt < dis[adjNode]) {
                dis[adjNode]=dis[node] + adjWt;
                pq.push({adjNode,dis[adjNode]});
            }
        }
    }

    return dis[dest];
}


    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pair<ll,ll>> adjList[n];
        for (auto &edge:edges) {
            ll from=edge[0];
            ll to=edge[1];
            ll wt=edge[2];

            if(wt!=-1){
                adjList[from].push_back({to,wt});
                adjList[to].push_back({from,wt});
            }
        }

        ll shortestDisWithoutMinus1s=f(n,adjList,source,destination);

        if(shortestDisWithoutMinus1s < target) return {};

        if(shortestDisWithoutMinus1s == target){
            for(auto &edge:edges) if(edge[2]==-1) edge[2]=2e9;
            return edges;
        }

        for (auto &edge:edges) {
            ll from=edge[0];
            ll to=edge[1];
            if(edge[2] != -1) continue;

            edge[2]=1;
            adjList[from].push_back({to,1});
            adjList[to].push_back({from,1});

            ll newShortestDistanceAfterChangingEachNegativeEdge = f(n,adjList,source,destination);
            if (newShortestDistanceAfterChangingEachNegativeEdge <= target) {
                edge[2] += target-newShortestDistanceAfterChangingEachNegativeEdge;
                for (auto &edge:edges) if(edge[2]==-1) edge[2]=2e9;
                return edges;
            }
        }

        return {};
    }
};