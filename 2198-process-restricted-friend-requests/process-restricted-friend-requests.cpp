class DisjointSet {
        public:

    vector<int> rank, parent, sizee;
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

    vector<int> askSize(){
        return sizee;
    }

    vector<int> askParent(){
        return parent;
    }

};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet ds(n);

        vector<bool>ans;

        for(int i=0;i<requests.size();i++){
            DisjointSet ds_copy=ds;
            int u=requests[i][0];
            int v=requests[i][1];

            ds_copy.unionBySize(u,v);

            int mark=0;
            for(auto &it2:restrictions){
                int u2=it2[0];
                int v2=it2[1];

                int ulp_u=ds_copy.findUPar(u2);
                int ulp_v=ds_copy.findUPar(v2);

                if(ulp_u==ulp_v){
                    ans.push_back(false);
                    mark=1;
                    break;
                }

            }

            if(mark==0){
                ans.push_back(true);
                ds.unionBySize(u,v);
            }
        }

        return ans;
    }
};