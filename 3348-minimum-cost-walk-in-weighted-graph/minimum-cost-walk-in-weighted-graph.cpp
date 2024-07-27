class DisjointSet {
    vector<int> rank, parent, sizee;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1);
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
    }

};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);

        vector<int>cost(n,-1);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            int ult_u=ds.findUPar(u);
            int ult_v=ds.findUPar(v);

            if(ult_u != ult_v){
                ds.unionByRank(ult_u , ult_v);
                cost[ult_u] &= cost[ult_v];
                cost[ult_v] &= cost[ult_u];
            }
            cost[ult_u] &= wt;
            cost[ult_v] &= wt;
        }

        vector<int>ans;
        for(auto &it:query){
            int u=it[0];
            int v=it[1];

            int ult_u=ds.findUPar(u);
            int ult_v=ds.findUPar(v);

            if(u==v) ans.push_back (0);
            else if(ult_u != ult_v){
                ans.push_back (-1) ;
            }
            else{
                ans.push_back ( cost[ult_u] );
            }
        }

        return ans;
    }
};