
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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=n;

        DisjointSet ds(n*m*4);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int root=(i*n+j)*4;

                if(grid[i][j]==' '){
                    ds.unionBySize(root,root+1);
                    ds.unionBySize(root+2,root+3);
                    ds.unionBySize(root+1,root+3);
                    ds.unionBySize(root,root+2);
                }
                else if(grid[i][j]=='/'){
                    ds.unionBySize(root,root+1);
                    ds.unionBySize(root+2,root+3);
                }
                else{
                    ds.unionBySize(root,root+2);
                    ds.unionBySize(root+1,root+3);
                }

                if(i>=1)ds.unionBySize(root,root-4*n+3);
                if(i<=n-2)ds.unionBySize(root+3,root+4*n);
                if(j>=1)ds.unionBySize(root+1,root-4+2);
                if(j<=m-2)ds.unionBySize(root+2,root+4+1);
            }
        }

        int ans=0;
        for(int i=0;i<n*m*4;i++){
            if(ds.findUPar(i)==i)ans++;
        }
        return ans;
    }
};