using ll=long long;
const int MAXN=1E5;
const ll INF=LLONG_MAX;

class Solution {
public:

int n;
vector<pair<int,int>>g[MAXN],gr[MAXN];

vector<ll> dijsktra(int src,bool rev){
    vector<ll>dist(n,INF);
    dist[src]=0;

    set<pair<int,ll>>st;
    st.insert({0,src});

    while(!st.empty()){
        auto it=*st.begin();
        ll d=it.first;
        int node=it.second;
        
        st.erase(st.begin());

        if(d > dist[node]) continue;

        auto& adj=rev==1 ? gr[node] : g[node];

        for(auto &c:adj){
            int child=c.first;
            int w=c.second;

            if(dist[node] + w < dist[child]){
                if(dist[child] != INF) st.erase({dist[child],child});
                dist[child] = dist[node] + w;
                st.insert({dist[child],child});
            }
        }
    }

    return dist;
}

    long long minimumWeight(int N, vector<vector<int>>& edges, int src1, int src2, int dest) {
        for(auto &c:edges){
            int u=c[0],v=c[1],w=c[2];
            g[u].push_back({v,w});
            gr[v].push_back({u,w});
        }

        n=N;

        vector<ll>src1_to_all=dijsktra(src1,0);
        vector<ll>src2_to_all=dijsktra(src2,0);
        vector<ll>dest_to_all=dijsktra(dest,1);

        if(src1_to_all[dest]==INF || src2_to_all[dest]==INF) return -1;

        ll res=INF;
        for(int j=0;j<n;j++){
            if(src1_to_all[j]==INF || src2_to_all[j]==INF || dest_to_all[j]==INF) continue;
            res=min(res,src1_to_all[j] + src2_to_all[j] + dest_to_all[j]);
        }

        return res;
    }
};