class Solution {
public:

int res=INT_MAX;
vector<int>g[1000];

    int findShortestCycle(int n, vector<vector<int>>& edges) {

        for(auto &c:edges){
            int u=c[0];
            int v=c[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            vector<int>dist(n,-1),par(n,-1);
            dist[i]=0;
            queue<int>q;
            q.push(i);

            while(!q.empty()){
                auto node=q.front();
                q.pop();

                for(auto &c:g[node]){
                    if(dist[c]==-1){
                        dist[c]=dist[node]+1;
                        par[c]=node;
                        q.push(c);
                    }
                    else if(c != par[node]){
                        //back-edge-forming-cycle
                        res=min(res,dist[node] + dist[c] + 1);
                    }
                }
            }
        }

        return (res==INT_MAX) ? -1 : res;
    }
};