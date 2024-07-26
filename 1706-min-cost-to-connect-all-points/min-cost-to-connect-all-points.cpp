class DisjointSet {
    public:
    vector<int> rank, parent, sizee;
    int flag;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1);
        flag=n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sizee[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        flag--;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (sizee[ulp_u] < sizee[ulp_v]) {
            parent[ulp_u] = ulp_v;
            sizee[ulp_v] += sizee[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            sizee[ulp_u] += sizee[ulp_v];
        }
        flag--;
    }
    bool isSingleComponentLeftOrNot(){
        return flag==1;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n=points.size();
        vector<pair<int,pair<int,int>>>edges;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                auto p1=points[i];
                auto p2=points[j];
                int d=abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
                edges.push_back({d,{i,j}});
            }
        }

        sort(edges.begin(),edges.end());

        DisjointSet ds(n);
        int mstWt=0;
        for(auto &it:edges){
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mstWt;
    }
};