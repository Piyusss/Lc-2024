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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);


        for(auto it:equations){
            if(it[1]=='='){
                ds.unionBySize(it[0]-'a',it[3]-'a');
            }
        }
        for(auto it:equations){
            char sign=it[1];

            int ult_u=ds.findUPar(it[0]-'a');
            int ult_v=ds.findUPar(it[3]-'a');

            if(sign == '!'){
               if(ult_u==ult_v)return 0;
            }
        }
        return 1;
    }
};