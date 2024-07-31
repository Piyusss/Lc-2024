
class DisjointSet {
    vector<int> rank, parent, sizee;
    int flag;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1);
        flag=0;
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
        flag++;
    }
    int isFlag(){
        return flag;
    }

};

class Solution {
public:
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int force_edge,int n){

        int mstWt=0;
        DisjointSet ds(n);
        
        if(force_edge!=-1) {
            ds.unionBySize(vec[force_edge][0],vec[force_edge][1]);
            mstWt+=vec[force_edge][2];
        }
        
        for(int i=0;i<vec.size();i++) {
            if(i==skip_edge)continue;
        
            int u=vec[i][0];
            int v=vec[i][1];
            int wt=vec[i][2];

            if(ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionBySize(u,v);
                mstWt+=wt;
            }
        }

        if(ds.isFlag()!=n-1)return 1e9;
        return mstWt;
    }
    
    static bool comp(vector<int>& v1,vector<int>& v2){
        return v1[2]<v2[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();

        for(int i = 0; i < m; i++)edges[i].push_back(i);
        sort(edges.begin(), edges.end(), comp);
        
        int original_mst_weight=Kruskal(edges,-1,-1,n);
        vector<int>c,pc;
        for(int i=0;i<m;i++){
            if(Kruskal(edges,i,-1,n) > original_mst_weight) c.push_back(edges[i][3]); 
            else if(Kruskal(edges,-1,i,n) == original_mst_weight) pc.push_back(edges[i][3]);
        }

        return {c,pc};
        
    }
};