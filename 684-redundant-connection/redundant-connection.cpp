
class DisjointSet {
    public:
    vector<int> rank, parent, sizee;
    int flag;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1,1);
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

    bool unionBySize(int u, int v,int child_ka_parent,int parent_ka_parent ) {

        if (child_ka_parent != v)
            return false;

        if (parent_ka_parent == child_ka_parent)
            return false;

        parent[v]=u;
        flag--;
        return true;
    }
    bool isSingleComponentLeftOrNot(){
        return flag==1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n=edges.size();
        
        DisjointSet ds(n);
        
        vector<int>ans(2,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionByRank(u,v);
            }
            else{
                ans[0]=u;
                ans[1]=v;
            }
        }
        return ans;
    }
};