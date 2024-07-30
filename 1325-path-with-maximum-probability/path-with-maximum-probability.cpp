class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adjList[n];

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];

            adjList[u].push_back({v,prob});
            adjList[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>>pq;
        pq.push({(double)1,start_node});

        vector<double>dis(n,0);
        dis[start_node]=(double)1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            double d=it.first;
            int node=it.second;

            for(auto &it:adjList[node]){
                int adjNode=it.first;
                double path_len=it.second;
                if(d*path_len>dis[adjNode]){
                    dis[adjNode]=d*path_len;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }

        return dis[end_node];
    }
};