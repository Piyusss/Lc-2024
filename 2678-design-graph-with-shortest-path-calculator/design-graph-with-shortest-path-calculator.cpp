class Graph {
public:

int n;
vector<pair<int,int>>adjList[100+1];

    Graph(int N, vector<vector<int>>& edges) {
        n=N;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adjList[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adjList[u].push_back({v,wt});
    }
    
    int shortestPath(int src, int dest) {
        vector<int>dis(n+1,1e9);
        dis[src]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto it=pq.top();
            int curDis=it.first;
            int curNode=it.second;
            pq.pop();

            for(auto &childIt:adjList[curNode]){
                int adjNode=childIt.first;
                int adjDis=childIt.second;

                if(curDis+adjDis < dis[adjNode]){
                    dis[adjNode]=curDis + adjDis;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }

        return dis[dest]==1e9 ? -1 : dis[dest];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */