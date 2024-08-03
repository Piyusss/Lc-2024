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

    int sizeOfComponent(int ult_p){
        return sizee[ult_p];
    }

};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet ds(n+1);

        for(int i=1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                if(i>threshold){
                    ds.unionBySize(i,j);
                }
            }
        }

        vector<bool>ans(queries.size(),false);

        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];

            int ulp_u=ds.findUPar(u);
            int ulp_v=ds.findUPar(v);

            if(ulp_u==ulp_v)ans[i]=true;
        }

        return ans;
    }
};