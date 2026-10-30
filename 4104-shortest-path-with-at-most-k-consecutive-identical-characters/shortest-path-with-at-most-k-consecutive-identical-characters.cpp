class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int m=edges.size();
        
        vector<vector<pair<int,int>>>g(n);
        for(auto &e:edges) g[e[0]].push_back({e[1],e[2]});

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        vector<vector<int>>d(n,vector<int>(k+1,1e9));

        q.push({0,0,1});
        d[0][1]=0;

        while(!q.empty()){
            auto [w,u,c]=q.top();
            q.pop();

            if(w>d[u][c]) continue;

            for(auto [v,x]:g[u]){
                int t=labels[v]==labels[u]?c+1:1;

                if(t<=k&&w+x<d[v][t]){
                    d[v][t]=w+x;
                    q.push({w+x,v,t});
                }
            }
        }

        int ans=1e9;
        for(int i=0;i<=k;i++) ans=min(ans,d[n-1][i]);
        return ans==1e9?-1:ans;
    }
};