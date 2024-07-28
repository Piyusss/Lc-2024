
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
    int minSwapsCouples(vector<int>& nums) {
        int n=nums.size();
        int nn=(n-1)/2+1;
        DisjointSet ds(nn);

        for(int i=0;i<n-1;i+=2){
            int u=nums[i]/2;
            int v=nums[i+1]/2;
            ds.unionBySize(u,v);
        }


        int cntOfUltParents=0;
        for(int i=0;i<nn;i++)if(ds.findUPar(i)==i)cntOfUltParents++;
        return (n/2)-cntOfUltParents;
    }
};