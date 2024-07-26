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

static bool comp(vector<int>a,vector<int>b){
    return a[0]>b[0];
}

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges){
        sort(edges.begin(),edges.end(),comp);

        DisjointSet Alice(n);
        DisjointSet Bob(n);

        int cnt=0;
        for(auto &it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];

            if(type==3){
                int mark=0;
                if(Alice.findUPar(u)!=Alice.findUPar(v)){
                    Alice.unionBySize(u,v);
                    mark=1;
                }
                if(Bob.findUPar(u)!=Bob.findUPar(v)){
                    Bob.unionBySize(u,v);
                    mark=1;
                }
                if(mark==1)cnt++;
            }
            else if(type==1){
                if(Alice.findUPar(u)!=Alice.findUPar(v)){
                    Alice.unionBySize(u,v);
                    cnt++;
                }
            }
            else{
                if(Bob.findUPar(u)!=Bob.findUPar(v)){
                    Bob.unionBySize(u,v);
                    cnt++;
                }
            }
        }

        if(Alice.isSingleComponentLeftOrNot() && Bob.isSingleComponentLeftOrNot())return edges.size()-cnt;
        return -1;
    }
};