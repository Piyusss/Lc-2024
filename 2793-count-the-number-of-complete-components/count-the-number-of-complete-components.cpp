class DisjointSet {
    vector<int> parent, sizee, edgeCnt;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        sizee.resize(n + 1);
        edgeCnt.resize(n + 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sizee[i] = 1;
            edgeCnt[i] = 0;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v){
            edgeCnt[ulp_v] += 1;
            return;
        }

        if (sizee[ulp_u] < sizee[ulp_v]) {
            parent[ulp_u] = ulp_v;
            sizee[ulp_v] += sizee[ulp_u];
            edgeCnt[ulp_v] += edgeCnt[ulp_u];
            edgeCnt[ulp_v] += 1;
        }
        else {
            parent[ulp_v] = ulp_u;
            sizee[ulp_u] += sizee[ulp_v];
            edgeCnt[ulp_u] += edgeCnt[ulp_v];
            edgeCnt[ulp_u] += 1;
        }
    }

    int sizeOfComponent(int ult_p){
        return sizee[ult_p];
    }

    int getEdgeCount(int ulp_p){
        return edgeCnt[ulp_p];
    }

};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n+1);

        for(auto &c:edges){
            int u=c[0];
            int v=c[1];
            ds.unionBySize(u,v);
        }

        vector<int>mark(n);
        int cnt=0;

        for(int i=0;i<n;i++){
            int ulp=ds.findUPar(i);
            if(mark[ulp]==1) continue;

            int soc=ds.sizeOfComponent(ulp);
            int ec=ds.getEdgeCount(ulp);
            cout<<soc<<" "<<ec<<endl;

            if(soc==1 || soc==2) cnt+=1;
            else{
                int req=(soc*(soc-1))/2;
                if(ec==req) cnt+=1;
            }

            mark[ulp]=1;
        }

        return cnt;
    }
};