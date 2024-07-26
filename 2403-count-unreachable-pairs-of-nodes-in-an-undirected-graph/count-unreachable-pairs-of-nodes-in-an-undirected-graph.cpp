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
    long long countPairs(int n, vector<vector<int>>& edges){
        DisjointSet ds(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            ds.unionBySize(u,v);
        }

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)]++;
        }

        long long temp=n;
        long long ans=0;
        for(auto &it:mp){
            ans+= (it.second*(temp-it.second));
            temp-=it.second;
        }
        return ans;
    }
};